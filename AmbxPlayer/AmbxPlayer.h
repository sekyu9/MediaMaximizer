
// AmbxPlayer.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CAmbxPlayerApp:
// �� Ŭ������ ������ ���ؼ��� AmbxPlayer.cpp�� �����Ͻʽÿ�.
//

class CAmbxPlayerApp : public CWinApp
{
public:
	CAmbxPlayerApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CAmbxPlayerApp theApp;