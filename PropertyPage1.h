#pragma once
#include "afxwin.h"


// CPropertyPage1 ��ȭ �����Դϴ�.

class CPropertyPage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage1)

public:
	CPropertyPage1();
	virtual ~CPropertyPage1();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString m_miningModel;
	virtual BOOL OnInitDialog();
	virtual BOOL OnKillActive();
	afx_msg void OnEnChangeEdit1();
	CEdit m_gms;
	afx_msg void OnBnClickedOpengms();
	CString m_strPathName;
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
};
