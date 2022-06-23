// PropertyPage5.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage5.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"
#include "WizardView.h"
#include "WizardDoc.h"

// CPropertyPage5 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPropertyPage5, CPropertyPage)

CPropertyPage5::CPropertyPage5()
	: CPropertyPage(IDD_DIALOG5)
{

}

CPropertyPage5::~CPropertyPage5()
{
}

void CPropertyPage5::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPropertyPage5, CPropertyPage)
END_MESSAGE_MAP()


// CPropertyPage5 메시지 처리기입니다.


BOOL CPropertyPage5::OnSetActive()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CPropSheet* pSheet = (CPropSheet*)GetParent();
	
	return CPropertyPage::OnSetActive();
}


BOOL CPropertyPage5::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CPropSheet* pSheet = (CPropSheet*)GetParentSheet();
	pSheet->SetWizardButtons(PSWIZB_FINISH | PSWIZB_BACK);
	pSheet->SetDlgItemText(12325, _T("학습실행"));

	SetDlgItemText(IDC_STATIC2, pSheet->m_algorithm);
	SetDlgItemText(IDC_STATIC3, pSheet->m_episode);
	SetDlgItemText(IDC_STATIC9, pSheet->m_nHidden);
	SetDlgItemText(IDC_STATIC4, pSheet->m_learnRate);
	SetDlgItemText(IDC_STATIC5, pSheet->m_discountRate);
	SetDlgItemText(IDC_STATIC7, pSheet->m_independent);
	SetDlgItemText(IDC_STATIC8, pSheet->m_dependent);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}



