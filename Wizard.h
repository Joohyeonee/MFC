
// Wizard.h : Wizard ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWizardApp:
// �� Ŭ������ ������ ���ؼ��� Wizard.cpp�� �����Ͻʽÿ�.
//

class CWizardApp : public CWinApp
{
public:
	CWizardApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWizardApp theApp;
