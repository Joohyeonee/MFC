#pragma once


// CPropertyPage5 대화 상자입니다.

class CPropertyPage5 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage5)

public:
	CPropertyPage5();
	virtual ~CPropertyPage5();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnSetActive();
	virtual BOOL OnInitDialog();
};
