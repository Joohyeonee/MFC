#pragma once
#include "afxwin.h"


// CPropertyPage4 ��ȭ �����Դϴ�.

class CPropertyPage4 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage4)

public:
	CPropertyPage4();
	virtual ~CPropertyPage4();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual LRESULT OnWizardNext();
	CComboBox m_dependent;
	CComboBox m_independent;
	virtual BOOL OnSetActive();
};
