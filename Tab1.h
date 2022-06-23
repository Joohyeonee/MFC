#pragma once
#include "afxwin.h"
#include "PropSheet.h"

// CTab1 대화 상자입니다.

class CTab1 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTab1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
