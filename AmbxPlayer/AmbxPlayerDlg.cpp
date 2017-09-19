
// AmbxPlayerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "afxwin.h"
#include "AmbxPlayer.h"
#include "AmbxPlayerDlg.h"
#include "afxdialogex.h"
#include "extra.h"
using namespace std;
using namespace xercesc;

typedef map<string, string> AttributeMap;
void parseXML(SAXParser* parser, const char* xmlFile);


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAmbxPlayerDlg ��ȭ ����

CAmbxPlayerDlg::CAmbxPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAmbxPlayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

// ���
void CAmbxPlayerDlg::Play()
{
	m_MPlayer.Play(m_videoPlayPos);
	SetTimer(IDT_PLAYTIME, 100, NULL);

	m_btnPlay.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
	m_btnPause.EnableWindow(TRUE);
}

// �Ͻ�����
void CAmbxPlayerDlg::Pause()
{
	m_MPlayer.Pause();
}

// ����
void CAmbxPlayerDlg::Stop()
{
	KillTimer(IDT_PLAYTIME);

	m_MPlayer.Stop();
	m_videoPlayPos = 0;
}

void CAmbxPlayerDlg::parseXML(SAXParser* parser, const char* xmlFile)
{
    try {
        parser->parse(xmlFile);
    }
    catch (const XMLException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (const SAXParseException& toCatch) {
        char* message = XMLString::transcode(toCatch.getMessage());
        cout << "Exception message is: \n"
             << message << "\n";
        XMLString::release(&message);
    }
    catch (...) {
        cout << "Unexpected Exception \n" ;
    }
}

void CAmbxPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_VIDEO_SEEK, m_videoSeekSlider);
	DDX_Control(pDX, IDC_BUTTON_OPEN, m_btnOpen);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
	DDX_Control(pDX, IDC_BUTTON_PLAY, m_btnPlay);
	DDX_Control(pDX, IDC_BUTTON_PAUSE, m_btnPause);
	DDX_Control(pDX, IDC_STATIC_VIDEO_VIEW, m_staticVideoView);
}

BEGIN_MESSAGE_MAP(CAmbxPlayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_HSCROLL()
	ON_WM_DESTROY()
	ON_WM_SIZE()

	ON_BN_CLICKED(IDC_BUTTON_OPEN, &CAmbxPlayerDlg::OnClickedButtonOpen)
	ON_BN_CLICKED(IDC_BUTTON_ADDSEM, &CAmbxPlayerDlg::OnClickedButtonAddSem)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, &CAmbxPlayerDlg::OnClickedButtonPause)
	ON_BN_CLICKED(IDC_BUTTON_PLAY, &CAmbxPlayerDlg::OnClickedButtonPlay)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CAmbxPlayerDlg::OnClickedButtonStop)

	ON_MESSAGE(WM_PLAYTIME_UPDATE, &CAmbxPlayerDlg::OnPlaytimeUpdate)
	ON_MESSAGE(WM_MPLAYER_DURATION, &CAmbxPlayerDlg::OnMplayerDuration)
	ON_MESSAGE(WM_MPLAYER_PLAYPOS, &CAmbxPlayerDlg::OnMplayerPlaypos)
	ON_MESSAGE(WM_MPLAYER_CACHEFILL, &CAmbxPlayerDlg::OnMplayerCachefill)
	ON_MESSAGE(WM_MPLAYER_NOSTREAM_FOUND, &CAmbxPlayerDlg::OnMplayerNostreamFound)
	ON_MESSAGE(WM_MPLAYER_EXIT, &CAmbxPlayerDlg::OnMplayerExit)
	ON_MESSAGE(WM_MPLAYER_CONNECTING_TO_SERVER, &CAmbxPlayerDlg::OnMplayerConnectingToServer)
	ON_MESSAGE(WM_MPLAYER_PAUSED, &CAmbxPlayerDlg::OnMplayerPaused)
	ON_MESSAGE(WM_MPLAYER_PLAY, &CAmbxPlayerDlg::OnMplayerPlay)
	ON_MESSAGE(WM_MPLAYER_START_TIME, &CAmbxPlayerDlg::OnMplayerStartTime)
	ON_STN_CLICKED(IDC_STATIC_VIDEO_VIEW, &CAmbxPlayerDlg::OnStnClickedStaticVideoView)
END_MESSAGE_MAP()


// CAmbxPlayerDlg �޽��� ó����

BOOL CAmbxPlayerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//ShowWindow(SW_SHOWMAXIMIZED);

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	HWND point = ::GetDlgItem(m_hWnd, IDC_SLIDER_VIDEO_SEEK);

	m_btnPlay.EnableWindow(FALSE);
	m_btnStop.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);

	// mplayer.exe ���� ���
	CString mplayerPath(_T("C:/Users/Sekyu/Desktop/�� ���� (4)/mplayer/mplayer.exe"));

	// mplayer ���
	m_MPlayer.SetMPlayerPath(mplayerPath.GetBuffer());
	// ������ ��¿��� �ڵ�
	m_MPlayer.SetHWNDView(m_staticVideoView.GetSafeHwnd());
	// �θ������� �ڵ�
	m_MPlayer.SetHWNDParent(GetSafeHwnd());

	m_startTime = 0;
	m_videoPlayPos = 0;
	m_duration = 0;
	m_isSeeking = FALSE;

	engine = new Engine();
	ambx = new Ambx();

	num = 100;

	SendMessage(WM_PLAYTIME_UPDATE,0);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CAmbxPlayerDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//if(m_staticVideoView.GetSafeHwnd()) {
	// m_staticVideoView.SetWindowPos(NULL,0,0,cx,cy,SWP_NOZORDER);
	//}

	if(nType == SIZE_MINIMIZED)
	{
		//â�� �ּ�ȭ�� ó��

	}
	else if(nType == SIZE_RESTORED)
	{
		//â�� ����ȭ�� ó��
		CRect rt(25,25,cx-30, cy-140);

		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC_VIDEO_VIEW);
		CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_SLIDER_VIDEO_SEEK);
		CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_BUTTON_OPEN);
		CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_BUTTON_STOP);
		CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_BUTTON_PLAY);
		CEdit* pEdit5 = (CEdit*)GetDlgItem(IDC_BUTTON_PAUSE);
		CEdit* pEdit6 = (CEdit*)GetDlgItem(IDC_STATIC_PLAYTIME);
		CEdit* pEdit7 = (CEdit*)GetDlgItem(IDC_BUTTON_ADDSEM);

		if(pEdit->GetSafeHwnd())
		{
			pEdit->MoveWindow( rt );
			pEdit1->SetRedraw(TRUE);
			pEdit2->SetRedraw(TRUE);
			pEdit3->SetRedraw(TRUE);
			pEdit4->SetRedraw(TRUE);
			pEdit5->SetRedraw(TRUE);
			pEdit6->SetRedraw(TRUE);
			pEdit7->SetRedraw(TRUE);
		}

		//SetRedraw(TRUE);
	}
	else if(nType == SIZE_MAXIMIZED)
	{
		CRect rt(10,10,cx-10, cy-10);
		
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_STATIC_VIDEO_VIEW);
		CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_SLIDER_VIDEO_SEEK);
		CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_BUTTON_OPEN);
		CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_BUTTON_STOP);
		CEdit* pEdit4 = (CEdit*)GetDlgItem(IDC_BUTTON_PLAY);
		CEdit* pEdit5 = (CEdit*)GetDlgItem(IDC_BUTTON_PAUSE);
		CEdit* pEdit6 = (CEdit*)GetDlgItem(IDC_STATIC_PLAYTIME);
		CEdit* pEdit7 = (CEdit*)GetDlgItem(IDC_BUTTON_ADDSEM);

		if(pEdit->GetSafeHwnd())
		{
			pEdit->MoveWindow( rt );
			pEdit1->SetRedraw(FALSE);
			pEdit2->SetRedraw(FALSE);
			pEdit3->SetRedraw(FALSE);
			pEdit4->SetRedraw(FALSE);
			pEdit5->SetRedraw(FALSE);
			pEdit6->SetRedraw(FALSE);
			pEdit7->SetRedraw(FALSE);
		}
		
		//SetRedraw(FALSE);
		//â�� �ִ�ȭ�� ó��
	}

}

void CAmbxPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CAmbxPlayerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CAmbxPlayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���� �÷��̱��� ���� ����
void CAmbxPlayerDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch(nIDEvent)
	{
	case IDT_PLAYTIME:
		if(
			!m_isSeeking
			&& m_MPlayer.GetPlaybackStatus() == CMPlayer::PB_PLAY
			&& m_MPlayer.GetControlStatus() != CMPlayer::CS_SEEK
		)
		{
			int currentPos = m_videoPlayPos - m_startTime;
			SendMessage(WM_PLAYTIME_UPDATE, (WPARAM)currentPos);
			m_videoSeekSlider.SetPos(currentPos);
		}
		break;
	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}

// ������ Ž��
void CAmbxPlayerDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if(pScrollBar)
	{
		if(pScrollBar == (CScrollBar *)&m_videoSeekSlider)
		{
			int nPos = m_videoSeekSlider.GetPos();

			switch(nSBCode)
			{
			case SB_ENDSCROLL:
				m_isSeeking = FALSE;
				m_MPlayer.Seek(nPos);
				m_videoPlayPos = nPos;
				break;
			default:
				m_isSeeking = TRUE;
				break;
			}

			SendMessage(WM_PLAYTIME_UPDATE, (WPARAM)nPos);
		}
 
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CAmbxPlayerDlg::OnDestroy()
{
	CDialogEx::OnDestroy();
}

// ������ ���� ����
void CAmbxPlayerDlg::OnClickedButtonOpen()
{
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, NULL);

	if(IDOK == dlg.DoModal())
	{
		m_MPlayer.SetVODPath(dlg.GetPathName().GetBuffer());	

		Play();
	}
}

// SEM ���� ����
void CAmbxPlayerDlg::OnClickedButtonAddSem()
{
	Stop();

	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, NULL);

	//std::string strTemp = (LPSTR)(LPCTSTR)cstrTemp;
	if(IDOK == dlg.DoModal())
	{		
		//XMLParser start-----------------------
		try{
			XMLPlatformUtils::Initialize();
		}catch(const XMLException& toCatch){
			char* message = XMLString::transcode(toCatch.getMessage());
			cout<< "Error during initialization! :\n"
				<< message << "\n";
			XMLString::release(&message);
			return;
		}
		SAXParser* parser = new SAXParser();
		parser->setDoNamespaces(true);

		UXSaxHandler* docHandler = new UXSaxHandler();
		ErrorHandler* errHandler = (ErrorHandler*) docHandler;

		parser -> setDocumentHandler(docHandler);
		parser -> setErrorHandler(errHandler);
			
		CT2CA fileName(dlg.GetPathName());
		buf_fName=((LPCSTR)fileName);

		while(1)
		{
			engine->setTitle((LPCSTR)fileName);

			// Load SEM and CIDL
			if(engine->loadXML(XML::SEM))			
				engine->createDeviceCommand();

			break;
		}
		m_btnPlay.EnableWindow(TRUE);
		num=0;
		
		//delete engine;
	}
}


void CAmbxPlayerDlg::OnClickedButtonPause()
{
	Pause();
}


void CAmbxPlayerDlg::OnClickedButtonPlay()
{
	if(m_MPlayer.GetPlaybackStatus() != CMPlayer::PB_PLAY)
	{
		Play();
	}
	else
	{
		Pause();
	}
}


void CAmbxPlayerDlg::OnClickedButtonStop()
{
	Stop();
}


afx_msg LRESULT CAmbxPlayerDlg::OnPlaytimeUpdate(WPARAM wParam, LPARAM lParam)
{
	DWORD cur = (DWORD)(wParam);
	DWORD dur = (DWORD)(m_duration);

	CString _cur;
	CString _dur;

	SecToTimeStr(cur, _cur);
	SecToTimeStr(dur, _dur);

	CString playTime;
	playTime.Format(_T("%s/%s"), _cur, _dur);

	SetDlgItemText(IDC_STATIC_PLAYTIME, playTime);

	if(num < engine->getIIDL()->getDeviceCommandList()->size())
	{
		if(dynamic_cast<ClockTickTimeType*>(engine->getIIDL()->getDeviceCommandList()->at(num)->getTimeStamp())->getPts()/1000 == cur)
		{
			ambx->Play(engine->getIIDL()->getDeviceCommandList(), num,  cur);
			num++;
			printf("%d\n", num);
		}
	}
	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerDuration(WPARAM wParam, LPARAM lParam)
{
	m_duration = (int)wParam; 
	m_videoSeekSlider.SetRange(0, (int)m_duration);

	SendMessage(WM_PLAYTIME_UPDATE, 0);

	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerPlaypos(WPARAM wParam, LPARAM lParam)
{
	if(m_MPlayer.GetControlStatus() != CMPlayer::CS_SEEK)
	{
		m_videoPlayPos = (int)wParam;
	}

	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerCachefill(WPARAM wParam, LPARAM lParam)
{
	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerNostreamFound(WPARAM wParam, LPARAM lParam)
{
	AfxMessageBox(_T("����� ���� �Ͽ����ϴ�."));
	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerExit(WPARAM wParam, LPARAM lParam)
{
	KillTimer(IDT_PLAYTIME);
	
	m_videoPlayPos = 0;
	SendMessage(WM_PLAYTIME_UPDATE,0);
	m_videoSeekSlider.SetPos(0);

	m_btnPlay.EnableWindow(TRUE);
	m_btnStop.EnableWindow(FALSE);
	m_btnPause.EnableWindow(FALSE);

	if(!m_MPlayer.IsPlayed())
	{
		//AfxMessageBox(_T("����� �����Ͽ����ϴ�."));
	}
	
	Play();
	
	num=0;
	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerConnectingToServer(WPARAM wParam, LPARAM lParam)
{
	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerPaused(WPARAM wParam, LPARAM lParam)
{
	m_btnPlay.EnableWindow(TRUE);
	m_btnStop.EnableWindow(TRUE);
	m_btnPause.EnableWindow(FALSE);

	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerPlay(WPARAM wParam, LPARAM lParam)
{
	m_btnPlay.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);
	m_btnPause.EnableWindow(TRUE);

	return 0;
}


afx_msg LRESULT CAmbxPlayerDlg::OnMplayerStartTime(WPARAM wParam, LPARAM lParam)
{
	m_startTime = (int)wParam;
	return 0;
}


BOOL CAboutDlg::PreTranslateMessage(MSG* pMsg)
{
	if(pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CAmbxPlayerDlg::OnStnClickedStaticVideoView()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
