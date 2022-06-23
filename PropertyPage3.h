#pragma once
#include "afxcmn.h"
#include "PropSheet.h"
#include "Tab1.h"

class CTab1;
class CTab2;

// CPropertyPage3 ��ȭ �����Դϴ�.

class CPropertyPage3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage3)

public:
	CPropertyPage3();
	virtual ~CPropertyPage3();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	CTab1 *pDlg1;
	CTab2 *pDlg2;
	CTabCtrl m_tab;
	CTab1 tab1;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
};

