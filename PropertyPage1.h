#pragma once
#include "afxwin.h"


// CPropertyPage1 대화 상자입니다.

class CPropertyPage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage1)

public:
	CPropertyPage1();
	virtual ~CPropertyPage1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
