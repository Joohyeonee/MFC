#pragma once


// CPropertyPage5 ��ȭ �����Դϴ�.

class CPropertyPage5 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPropertyPage5)

public:
	CPropertyPage5();
	virtual ~CPropertyPage5();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnSetActive();
	virtual BOOL OnInitDialog();
};
