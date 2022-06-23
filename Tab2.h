#pragma once
#include "afxwin.h"


// CTab2 대화 상자입니다.

class CTab2 : public CDialogEx
{
	DECLARE_DYNAMIC(CTab2)

public:
	CTab2(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTab2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TAB2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelendokActive();
	CString m_active1;
	CString m_layer1Active1;
	CString m_layer2Active1;
	CString str_nHidden;
	int m_nHidden1;
	CComboBox m_active;
	CComboBox m_layer1Active;
	CComboBox m_layer2Active;
	CComboBox m_nHidden;
	afx_msg void OnCbnSelendokNLayer();
	virtual BOOL OnInitDialog();
	CComboBox m_layer3Active;
	CComboBox m_layer4Active;
	CComboBox m_layer5Active;
	CComboBox m_layer6Active;
	CComboBox m_layerActive7;
	CComboBox m_layerActive8;
	CComboBox m_layer9Active;
	CComboBox m_layerActive10;

};
