// Calculatora.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCalculatoraApp:
// �йش����ʵ�֣������ Calculatora.cpp
//

class CCalculatoraApp : public CWinApp
{
public:
	CCalculatoraApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCalculatoraApp theApp;