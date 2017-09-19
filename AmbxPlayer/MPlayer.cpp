#include "stdafx.h"
#include "MPlayer.h"

CMPlayer::CMPlayer(void)
{
	playbackStatus = PB_STOP;
	controlStatus = CS_NONE;
	rxCommThread = NULL;
}

CMPlayer::CMPlayer(TSTRING mplayerPath, TSTRING vodPath, HWND hWndView, HWND hWndParent /* = NULL */)
{
	CMPlayer();

	SetMPlayerPath(mplayerPath);
	SetVODPath(vodPath);
	SetHWNDView(hWndView);
	SetHWNDParent(hWndParent);
}

void CMPlayer::SetMPlayerPath(TSTRING mplayerPath)
{
	this->mplayerPath = mplayerPath;
}

void CMPlayer::SetVODPath(TSTRING vodPath)
{
	this->vodPath = vodPath;
}

void CMPlayer::SetHWNDView(HWND hWndView)
{
	this->hWndView = hWndView;
}

void CMPlayer::SetHWNDParent(HWND hWndParent /* = NULL */)
{
	this->hWndParent = hWndParent;
}

RET::VALUES CMPlayer::Launch(int pos /*  pos = -1 */)
{
	STARTUPINFO si;
	SECURITY_ATTRIBUTES sa_attr;

	sa_attr.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa_attr.bInheritHandle = true;
	sa_attr.lpSecurityDescriptor = NULL;

	if(!CreatePipe(&outRx,&outTx,&sa_attr,4096))
	{
		return RET::CREATE_OUTPUT_PIPE_FAIL;
	}

	if(!CreatePipe(&inRx,&inTx,&sa_attr,4096))
	{
		return RET::CREATE_INPUT_PIPE_FAIL;
	}

	ZeroMemory(&si,sizeof(si));
	si.cb = sizeof(si);

	si.dwFlags |= STARTF_USESTDHANDLES;
	// 프로세스의 출력파이프 연결. 이 출력을 outRx 에서 읽음.
	si.hStdOutput = outTx;
	// 프로세스의 입력파이프 연결. 이 입력은 inTx 로 함.
	si.hStdInput = inRx;

	ZeroMemory(&pi, sizeof(pi));

	CString cmdLine;

	if(pos < 0)
	{
		cmdLine.Format(
			_T("\"%s\" -noquiet -nofs -nomouseinput -sub-fuzziness 1 -identify ")
			_T("-slave -vo direct3d -ao dsound -nokeepaspect -priority abovenormal ")
			_T("-nodr -double -wid %d -monitorpixelaspect 1 -embeddedfonts -fontconfig ")
			_T("-font Arial -subfont-autoscale 0 -subfont-osd-scale 20 ")
			_T("-subfont-text-scale 20 -subcp ISO-8859-1 -subpos 100 -volume 50 -cache 2048 ")
			_T("-osdlevel 0 -prefer-ipv4 -vf-add screenshot -noslices -af ")
			_T("scaletempo,equalizer=0:0:0:0:0:0:0:0:0:0 -softvol -softvol-max 110 \"%s\""), 
			mplayerPath.c_str(), 
			hWndView, 
			vodPath.c_str()
		);
	}
	else
	{
		cmdLine.Format(
			_T("\"%s\" -ss %d -noquiet -nofs -nomouseinput -sub-fuzziness 1 -identify ")
			_T("-slave -vo direct3d -ao dsound -nokeepaspect -priority abovenormal ")
			_T("-nodr -double -wid %d -monitorpixelaspect 1 -embeddedfonts -fontconfig ")
			_T("-font Arial -subfont-autoscale 0 -subfont-osd-scale 20 ")
			_T("-subfont-text-scale 20 -subcp ISO-8859-1 -subpos 100 -volume 50 -cache 2048 ")
			_T("-osdlevel 0 -prefer-ipv4 -vf-add screenshot -noslices -af ")
			_T("scaletempo,equalizer=0:0:0:0:0:0:0:0:0:0 -softvol -softvol-max 110 \"%s\""), 
			mplayerPath.c_str(), 
			pos,
			hWndView, 
			vodPath.c_str()
		);
	}

	bPlayed = FALSE;

	if(!CreateProcess(
		NULL,
		(TCHAR *)cmdLine.GetBuffer(),
		&sa_attr,
		&sa_attr,
		TRUE,
		CREATE_NO_WINDOW,
		NULL,
		NULL,
		&si,
		&pi
		)
	)
	{
		return RET::CREATE_PROCESS_FAIL;
	}

	rxCommThread = AfxBeginThread(&CMPlayer::RxCommThread, this);

	return RET::RET_OK;

}

HANDLE CMPlayer::GetOutTx()
{
	return outTx;
}

HANDLE CMPlayer::GetOutRx()
{
	return outRx;
}

HANDLE CMPlayer::GetInTx()
{
	return inTx;
}

HANDLE CMPlayer::GetInRx()
{
	return inRx;
}

CMPlayer::PLAYBACK_STATUS CMPlayer::GetPlaybackStatus()
{
	return playbackStatus;
}

void CMPlayer::SetPlaybackStatus(PLAYBACK_STATUS status)
{
	this->playbackStatus = status;
}

CMPlayer::CONTROL_STATUS CMPlayer::GetControlStatus()
{
	return controlStatus;
}

void CMPlayer::SetControlStatus(CONTROL_STATUS status)
{
	this->controlStatus = status;
}

// 출력값을 파싱
UINT CMPlayer::RxCommThread(LPVOID pParam)
{
	CMPlayer *mPlayer = (CMPlayer *)pParam;

	while(true)
	{
		char outputBuf[2048] = {0,};
		DWORD outputBytesRead;

		BOOL b_success = ReadFile(
			mPlayer->GetOutRx(),
			outputBuf,
			2047,
			&outputBytesRead,
			nullptr
			);

		if(outputBytesRead > 0)
		{
			// 동영상 시작시간 검출
			char *idStartTimeStart = strstr(outputBuf, "ID_START_TIME=");

			if(idStartTimeStart)
			{
				idStartTimeStart += strlen("ID_START_TIME=");
				char *idStartTimeEnd = strstr(idStartTimeStart, "\r\n");

				if(idStartTimeEnd)
				{
					char value[1024] = {0,};

					strncpy_s(value, idStartTimeEnd - idStartTimeStart +1, idStartTimeStart, _TRUNCATE);
					
					::PostMessage(mPlayer->hWndParent, WM_MPLAYER_START_TIME, (WPARAM)((int)atof(value)), 0);

				}
			}

			// 동영상 전체 running time 검출
			char *idLengthStart = strstr(outputBuf, "ID_LENGTH=");

			if(idLengthStart)
			{
				idLengthStart += strlen("ID_LENGTH=");
				char *idLengthEnd = strstr(idLengthStart, "\r\n");

				if(idLengthEnd)
				{
					char value[1024] = {0,};

					strncpy_s(value, idLengthEnd - idLengthStart +1, idLengthStart, _TRUNCATE);
					
					::PostMessage(mPlayer->hWndParent, WM_MPLAYER_DURATION, (WPARAM)((int)atof(value)), 0);

				}
			}

			// 플래이 포지션
			char *videoPlayPosStart = strstr(outputBuf, " V:");

			if(videoPlayPosStart)
			{
				videoPlayPosStart += strlen(" V:");
				char *videoPlayPosEnd = strstr(videoPlayPosStart, " A-V:");

				if(videoPlayPosEnd)
				{
					char value[1024] = {0,};

					strncpy_s(value, videoPlayPosEnd - videoPlayPosStart +1, videoPlayPosStart, _TRUNCATE);

					::PostMessage(mPlayer->hWndParent, WM_MPLAYER_PLAYPOS, (WPARAM)((int)atof(value)), 0);

					if(mPlayer->GetPlaybackStatus() != PB_PLAY )
					{
						mPlayer->bPlayed = TRUE;
						mPlayer->SetPlaybackStatus(PB_PLAY);
						::PostMessage(mPlayer->hWndParent, WM_MPLAYER_PLAY, 0, 0);
					}

					if(mPlayer->GetControlStatus() == CS_SEEK)
					{
						mPlayer->seekCompleteTriggerCount++;

						if(mPlayer->seekCompleteTriggerCount > SEEK_COMPLETE_THRESHOLD)
						{
							mPlayer->SetControlStatus(CS_SEEK_COMPLETE);
							mPlayer->seekCompleteTriggerCount = 0;
						}
					}
				}
			}

			// cache fill
			char *cacheFillStart = strstr(outputBuf, "Cache fill:");

			if(cacheFillStart)
			{
				cacheFillStart += strlen("Cache fill:");
				char *cacheFillEnd = strstr(cacheFillStart, "%");

				if(cacheFillEnd)
				{
					char value[1024] = {0,};

					strncpy_s(value, cacheFillEnd - cacheFillStart +1, cacheFillStart, _TRUNCATE);

					::PostMessage(mPlayer->hWndParent, WM_MPLAYER_CACHEFILL, (WPARAM)((int)atof(value)), 0);
				}
			}

			// No Stream Found
			char *noStreamFoundStart = strstr(outputBuf, "No stream found to handle url");
			if(noStreamFoundStart)
			{
				::PostMessage(mPlayer->hWndParent, WM_MPLAYER_NOSTREAM_FOUND, 0, 0);
			}

			// Stop, Quit
			char *idExitStart = strstr(outputBuf, "ID_EXIT=");

			if(idExitStart)
			{
				idExitStart += strlen("ID_EXIT=");
				char *idExitEnd = strstr(idExitStart, "\r\n");

				if(idExitEnd)
				{
					char value[1024] = {0,};

					strncpy_s(value, idExitEnd - idExitStart +1, idExitStart, _TRUNCATE);

					mPlayer->SetPlaybackStatus(PB_STOP);
					mPlayer->SetControlStatus(CS_QUIT_COMPLETE);

					::PostMessage(mPlayer->hWndParent, WM_MPLAYER_EXIT, 0, 0);
				}
			}

			// paused
			char *idPausedStart = strstr(outputBuf, "ID_PAUSED");

			if(idPausedStart)
			{
				mPlayer->SetPlaybackStatus(PB_PAUSE);
				mPlayer->SetControlStatus(CS_PAUSE_COMPLETE);
				::PostMessage(mPlayer->hWndParent, WM_MPLAYER_PAUSED, 0, 0);
			}

			// connecting to server
			char *connServerStart = strstr(outputBuf, "Connecting to server");

			if(connServerStart)
			{
				::PostMessage(mPlayer->hWndParent, WM_MPLAYER_CONNECTING_TO_SERVER, 0, 0);
			}
		}

	}

	return 0;
}

void CMPlayer::WriteCommand(TSTRING command)
{
	DWORD written;

	char *_command = unicode_to_ansi((TCHAR *)command.c_str());

	BOOL bWrite = WriteFile(GetInTx(), _command, strlen(_command), &written, NULL);

	delete[] _command;
}

void CMPlayer::Play(int pos /*= -1*/)
{
	if(playbackStatus == PB_PAUSE)
	{
		WriteCommand(_T("pause\r\n"));
	}
	else
	{
		Launch(pos);
	}
}

void CMPlayer::Pause()
{
	if(playbackStatus == PB_PLAY)
	{
		WriteCommand(_T("pause\r\n"));
		SetControlStatus(CS_PAUSE);
	}
}

void CMPlayer::Stop()
{
	WriteCommand(_T("quit\r\n"));
	SetControlStatus(CS_QUIT);
	SetPlaybackStatus(PB_STOP);
}

void CMPlayer::Seek(int pos)
{
	CString seek;
	seek.Format(_T("seek %d %d\r\n"), pos, 2);
	WriteCommand(seek.GetBuffer());
	SetControlStatus(CS_SEEK);
	seekCompleteTriggerCount = 0;
}

void CMPlayer::Terminate()
{
	if(rxCommThread)
	{
		TerminateThread(rxCommThread->m_hThread, 0);
		delete rxCommThread;
		rxCommThread = NULL;
	}	

	if(pi.hProcess)
	{
		TerminateProcess(pi.hProcess, 0);
	}
}

BOOL CMPlayer::IsPlayed()
{
	return bPlayed;
}

CMPlayer::~CMPlayer(void)
{
	Terminate();
}
