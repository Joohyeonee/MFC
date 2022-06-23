#pragma once
#include "afxwin.h"


// CPropertyPage4 대화 상자입니다.

class CPropertyPage4 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage4)

public:
	CPropertyPage4();
	virtual ~CPropertyPage4();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual LRESULT OnWizardNext();
	CComboBox m_dependent;
	CComboBox m_independent;
	virtual BOOL OnSetActive();
};
