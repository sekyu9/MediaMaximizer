
// AmbxPlayerDlg.h : ��� ����
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

// CAmbxPlayerDlg ��ȭ ����
class CAmbxPlayerDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CAmbxPlayerDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_AMBXPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
	// ������ ���� ���
	TSTRING m_vodPath;
	// ������ ���۽ð�
	int m_startTime;
	// ������ ��ü running time
	int m_duration;
	// ���� ������ �÷��� ����
	int m_videoPlayPos;
	// �����̴� ���ۿ���
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
