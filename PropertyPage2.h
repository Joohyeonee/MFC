#pragma once
#include "afxcmn.h"


// CPropertyPage2 ��ȭ �����Դϴ�.

class CPropertyPage2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage2)

public:
	CPropertyPage2();
	virtual ~CPropertyPage2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBringdata();
	CString m_strPathName;
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
};


