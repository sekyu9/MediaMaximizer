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

// ������ ��ü running time ����
#define WM_MPLAYER_DURATION				WM_USER + 3400
// ���� �������
#define WM_MPLAYER_PLAYPOS				WM_USER + 3401
// cachefill ����
#define WM_MPLAYER_CACHEFILL			WM_USER + 3402
// nostream found ����
#define WM_MPLAYER_NOSTREAM_FOUND		WM_USER + 3403
// ID_EXIT ����
#define WM_MPLAYER_EXIT					WM_USER + 3404
// Connection to Server ����
#define WM_MPLAYER_CONNECTING_TO_SERVER WM_USER + 3405
// �Ͻ����� �̺�Ʈ
#define WM_MPLAYER_PAUSED				WM_USER + 3406
// ��� �̺�Ʈ
#define WM_MPLAYER_PLAY					WM_USER + 3407
// ������ ���� �ð� ����
#define WM_MPLAYER_START_TIME			WM_USER + 3408

class CMPlayer
{
public:
	// ��� ����
	enum PLAYBACK_STATUS
	{
		// ����
		PB_STOP,
		// �Ͻ�����
		PB_PAUSE,
		// ���
		PB_PLAY
	};

	// �������
	enum CONTROL_STATUS
	{
		// ���� ���� ����
		CS_NONE,
		// Ž��
		CS_SEEK,
		// Ž�� �Ϸ�
		CS_SEEK_COMPLETE,
		// �Ͻ�����
		CS_PAUSE,
		// �Ͻ����� �Ϸ�
		CS_PAUSE_COMPLETE,
		// ����
		CS_QUIT,
		// �����Ϸ�
		CS_QUIT_COMPLETE
	};

private:
	static const int SEEK_COMPLETE_THRESHOLD = 10;
	int seekCompleteTriggerCount;

	// mplayer ������
	TSTRING mplayerPath;
	// ������ ������
	TSTRING vodPath;
	// ������ ��� ������ �ڵ�
	HWND hWndView;
	// �θ������� �ڵ�
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

