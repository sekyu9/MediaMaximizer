#pragma once

#include "stdafx.h"
#include <tchar.h>
#include <string>

namespace std
{
	typedef basic_string<TCHAR> tstring;
};

typedef std::tstring TSTRING;

// �����ڵ� -> �Ƚ��ڵ� ��ȯ
inline char *unicode_to_ansi(wchar_t *p_unicode_str)
{
	char *p_ansi_str;

	int size = 0;

	size = WideCharToMultiByte(CP_ACP, 0, p_unicode_str,-1, NULL,0,NULL,NULL);

	p_ansi_str = new char[size];
	ZeroMemory(p_ansi_str,size);

	WideCharToMultiByte(CP_ACP, 0, p_unicode_str,-1, p_ansi_str,size,NULL,NULL);

	return p_ansi_str;
}

// �ʴ����� ��:��:�� ��
inline void SecToTimeStr(DWORD sec, CString &buf)
{
	DWORD hh;
	DWORD ii;
	DWORD ss;

	hh = sec / 3600;
	ii = (sec % 3600) / 60;
	ss = (sec % 3600) % 60;

	buf.Format(_T("%02d:%02d:%02d"), hh, ii, ss);
}