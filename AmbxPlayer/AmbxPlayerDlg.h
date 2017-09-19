
// AmbxPlayerDlg.h : 헤더 파일
//

#pragma once

#include "afxcmn.h"
#include "afxwin.h"
#include "MPlayer.h"
#include "extra.h"
#include "afxwin.h"

#include <xercesc/parsers/SAXParser.hpp>
#include <xercesc/util/XMLString.hpp>
#include <iostream>
#include <vector>
#include <map>
#include "UXSAXHandler.h"
#include "SEMRootElement.h"
#include "ControlInfoRootElement.h"
#include "InteractionInfoRootElement.h"
#include "Engine.h"
#include "constants.h"
#include "Ambx.h"

#define IDT_PLAYTIME						0
#define WM_PLAYTIME_UPDATE				WM_USER + 3001

// CAmbxPlayerDlg 대화 상자
class CAmbxPlayerDlg : public CDialogEx
{
// 생성입니다.
public:
	CAmbxPlayerDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_AMBXPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void Play();
	void Pause();
	void Stop();
	void parseXML(SAXParser* parser, const char* xmlFile);
private:
	CSliderCtrl m_videoSeekSlider;
	CButton m_btnOpen;
	CButton m_btnStop;
	CButton m_btnPlay;
	CButton m_btnPause;
	CMPlayer m_MPlayer;
	CStatic m_staticVideoView;
	// 동영상 절대 경로
	TSTRING m_vodPath;
	// 동영상 시작시간
	int m_startTime;
	// 동영상 전체 running time
	int m_duration;
	// 현재 동영상 플래이 구간
	int m_videoPlayPos;
	// 슬라이더 조작여부
	BOOL m_isSeeking;

	Engine *engine;
	Ambx *ambx;
	int num;
	string buf_fName;

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDestroy();
	afx_msg void OnClickedButtonOpen();
	afx_msg void OnClickedButtonAddSem();
	afx_msg void OnClickedButtonPause();
	afx_msg void OnClickedButtonPlay();
	afx_msg void OnClickedButtonStop();

protected:
	afx_msg LRESULT OnPlaytimeUpdate(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerDuration(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerPlaypos(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerCachefill(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerNostreamFound(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerExit(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerConnectingToServer(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerPaused(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerPlay(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMplayerStartTime(WPARAM wParam, LPARAM lParam);
public:
	afx_msg void OnStnClickedStaticVideoView();
	void CAmbxPlayerDlg::OnSize(UINT nType, int cx, int cy);
};
