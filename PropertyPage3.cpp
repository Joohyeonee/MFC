// PropertyPage3.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Wizard.h"
#include "WizardView.h"
#include "PropertyPage3.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"
#include "Tab1.h"
#include "Tab2.h"

// CPropertyPage3 대화 상자입니다.

IMPLEMENT_DYNAMIC(CPropertyPage3, CPropertyPage)

CPropertyPage3::CPropertyPage3()
	: CPropertyPage(IDD_DIALOG3)
{
	
}

CPropertyPage3::~CPropertyPage3()
{
}

void CPropertyPage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CPropertyPage3, CPropertyPage)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CPropertyPage3::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CPropertyPage3 메시지 처리기입니다.


BOOL CPropertyPage3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CRect rect;
	m_tab.GetWindowRect(rect);
	m_tab.InsertItem(0, _T("강화학습 옵션"));
	m_tab.InsertItem(1, _T("신경망 옵션"));

	m_tab.SetCurSel(0);

	pDlg1 = new CTab1;
	pDlg1->Create(IDD_TAB1, &m_tab);
	pDlg1->MoveWindow(0, 20, rect.Width() - 5, rect.Height() - 5);
	pDlg1->ShowWindow(SW_SHOW);

	pDlg2 = new CTab2;
	pDlg2->Create(IDD_TAB2, &m_tab);
	pDlg2->MoveWindow(0, 20, rect.Width() - 5, rect.Height() - 5);
	pDlg2->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CPropertyPage3::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (IDC_TAB1 == pNMHDR->idFrom) {
		int iSelect = m_tab.GetCurSel();

		switch (iSelect) {
		case 0:
			pDlg1->ShowWindow(SW_SHOW);
			pDlg2->ShowWindow(SW_HIDE);
			break;
		case 1:
			pDlg1->ShowWindow(SW_HIDE);
			pDlg2->ShowWindow(SW_SHOW);
			break;
		}
	}
	*pResult = 0;
}


BOOL CPropertyPage3::OnSetActive()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CPropSheet* pSheet = (CPropSheet*)GetParentSheet();
	pSheet->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}


LRESULT CPropertyPage3::OnWizardNext()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	UpdateData(TRUE);
	CPropSheet* pSheet = (CPropSheet*)GetParentSheet();
	
	pDlg1->SubclassDlgItem(this->GetDlgCtrlID(), this);

	pDlg1->GetDlgItemText(IDC_ALGORITHM, pSheet->m_algorithm);
	pDlg1->GetDlgItemText(IDC_EPISODE, pSheet->m_episode);
	pDlg1->GetDlgItemText(IDC_DISCOUNT_RATE, pSheet->m_discountRate);
	pDlg1->GetDlgItemText(IDC_LEARN_RATE, pSheet->m_learnRate);
	pDlg2->GetDlgItemText(IDC_N_LAYER, pSheet->m_nHidden);

	return CPropertyPage::OnWizardNext();
}

