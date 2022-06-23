// PropertyPage4.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage4.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"


// CPropertyPage4 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPropertyPage4, CPropertyPage)

CPropertyPage4::CPropertyPage4()
	: CPropertyPage(IDD_DIALOG4)
{

}

CPropertyPage4::~CPropertyPage4()
{
}

void CPropertyPage4::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DEPENDENT, m_dependent);
	DDX_Control(pDX, IDC_INDEPENDENT, m_independent);

}


BEGIN_MESSAGE_MAP(CPropertyPage4, CPropertyPage)
END_MESSAGE_MAP()


// CPropertyPage4 메시지 처리기입니다.




BOOL CPropertyPage4::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	for (int i = 1; i < 6; i++) {
		CString str;
		str.Format(_T("A%d"), i);
		m_independent.AddString(str);
		m_dependent.AddString(str);
	}

	SetDlgItemText(IDC_ERROR, _T("5"));
	SetDlgItemText(IDC_UP_LIMIT, _T("200"));
	SetDlgItemText(IDC_DOWN_LIMIT, _T("-200"));
	SetDlgItemText(IDC_AMOUNT, _T("10"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}




LRESULT CPropertyPage4::OnWizardNext()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CString str_dependent;
	CString str_independent;
	
	GetDlgItemText(IDC_DEPENDENT, str_dependent);
	GetDlgItemText(IDC_INDEPENDENT, str_independent);

	if (str_dependent.IsEmpty() || str_independent.IsEmpty()) {
		AfxMessageBox(_T("변수를 선택하지 않았습니다"));
		return -1;
	}
	CPropSheet* pSheet = (CPropSheet*)GetParentSheet();

	GetDlgItemText(IDC_DEPENDENT, pSheet->m_dependent);
	GetDlgItemText(IDC_INDEPENDENT, pSheet->m_independent);

	SetModified(TRUE);
	return CPropertyPage::OnWizardNext();
}


BOOL CPropertyPage4::OnSetActive()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CPropSheet* pSheet = (CPropSheet*)GetParentSheet();
	pSheet->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
