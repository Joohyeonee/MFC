#pragma once
#include "afxwin.h"
#include "PropSheet.h"

// CTab1 ��ȭ �����Դϴ�.

class CTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTab1();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox m_yesno1;
	CComboBox m_algorithm;
	CString m_episode;
	CEdit m_discount_factor;
	CEdit m_learn_rate;
	afx_msg void OnCbnSelendokAlgorithm();
};
