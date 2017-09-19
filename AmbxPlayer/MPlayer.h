#pragma once

#include "stdafx.h"
#include <tchar.h>
#include <string>

#include <queue>

#include "extra.h"

namespace RET
{
	enum VALUES
	{
		RET_OK,
		CREATE_OUTPUT_PIPE_FAIL,
		CREATE_INPUT_PIPE_FAIL,
		CREATE_PROCESS_FAIL
	};
};

// 동영상 전체 running time 검출
#define WM_MPLAYER_DURATION				WM_USER + 3400
// 현재 재생구간
#define WM_MPLAYER_PLAYPOS				WM_USER + 3401
// cachefill 검출
#define WM_MPLAYER_CACHEFILL			WM_USER + 3402
// nostream found 검출
#define WM_MPLAYER_NOSTREAM_FOUND		WM_USER + 3403
// ID_EXIT 검출
#define WM_MPLAYER_EXIT					WM_USER + 3404
// Connection to Server 검출
#define WM_MPLAYER_CONNECTING_TO_SERVER WM_USER + 3405
// 일시중지 이벤트
#define WM_MPLAYER_PAUSED				WM_USER + 3406
// 재생 이벤트
#define WM_MPLAYER_PLAY					WM_USER + 3407
// 동영상 시작 시간 검출
#define WM_MPLAYER_START_TIME			WM_USER + 3408

class CMPlayer
{
public:
	// 재생 상태
	enum PLAYBACK_STATUS
	{
		// 중지
		PB_STOP,
		// 일시중지
		PB_PAUSE,
		// 재생
		PB_PLAY
	};

	// 제어상태
	enum CONTROL_STATUS
	{
		// 정의 되지 않음
		CS_NONE,
		// 탐색
		CS_SEEK,
		// 탐색 완료
		CS_SEEK_COMPLETE,
		// 일시중지
		CS_PAUSE,
		// 일시중지 완료
		CS_PAUSE_COMPLETE,
		// 중지
		CS_QUIT,
		// 중지완료
		CS_QUIT_COMPLETE
	};

private:
	static const int SEEK_COMPLETE_THRESHOLD = 10;
	int seekCompleteTriggerCount;

	// mplayer 절대경로
	TSTRING mplayerPath;
	// 동영상 절대경로
	TSTRING vodPath;
	// 동영상 출력 윈도우 핸들
	HWND hWndView;
	// 부모윈도우 핸들
	HWND hWndParent;
	PROCESS_INFORMATION pi;
	HANDLE outRx, outTx;
	HANDLE inRx, inTx;
	CWinThread *rxCommThread;
	PLAYBACK_STATUS playbackStatus;
	CONTROL_STATUS controlStatus;
	BOOL bPlayed;

public:
	CMPlayer(void);
	CMPlayer(TSTRING mplayerPath, TSTRING vodPath, HWND hWndView, HWND hWndParent = NULL);
	void SetMPlayerPath(TSTRING mplayerPath);
	void SetVODPath(TSTRING vodPath);
	void SetHWNDView(HWND hWndView);
	void SetHWNDParent(HWND hWndParent = NULL);
	RET::VALUES Launch(int pos = -1);
	void Play(int pos = -1);
	void Pause();
	void Stop();
	void Seek(int pos);
	PLAYBACK_STATUS GetPlaybackStatus();
	CONTROL_STATUS GetControlStatus();
	BOOL IsPlayed();
	void Terminate();
	~CMPlayer(void);

private:
	HANDLE GetOutRx();
	HANDLE GetOutTx();
	HANDLE GetInRx();
	HANDLE GetInTx();
	static UINT RxCommThread(LPVOID pParam);
	void SetPlaybackStatus(PLAYBACK_STATUS status);
	void SetControlStatus(CONTROL_STATUS status);
	void WriteCommand(TSTRING command);
};

