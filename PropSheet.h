#pragma once



// CPropSheet

class CPropSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropSheet)

public:
	CPropSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropSheet();
	virtual ~CPropSheet();


protected:
	DECLARE_MESSAGE_MAP()

public:
	CString m_nHidden;
	CString m_algorithm;
	CString m_episode;
	CString m_learnRate;
	CString m_discountRate;
	CString m_dependent;
	CString m_independent;
};


