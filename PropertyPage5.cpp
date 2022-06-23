// PropertyPage5.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage5.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"
#include "WizardView.h"
#include "WizardDoc.h"

// CPropertyPage5 ��ȭ �����Դϴ�.

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


// CPropertyPage5 �޽��� ó�����Դϴ�.


BOOL CPropertyPage5::OnSetActive()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CPropSheet* pSheet = (CPropSheet*)GetParent();
	
	return CPropertyPage::OnSetActive();
}


BOOL CPropertyPage5::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CPropSheet* pSheet = (CPropSheet*)GetParentSheet();
	pSheet->SetWizardButtons(PSWIZB_FINISH | PSWIZB_BACK);
	pSheet->SetDlgItemText(12325, _T("�н�����"));

	SetDlgItemText(IDC_STATIC2, pSheet->m_algorithm);
	SetDlgItemText(IDC_STATIC3, pSheet->m_episode);
	SetDlgItemText(IDC_STATIC9, pSheet->m_nHidden);
	SetDlgItemText(IDC_STATIC4, pSheet->m_learnRate);
	SetDlgItemText(IDC_STATIC5, pSheet->m_discountRate);
	SetDlgItemText(IDC_STATIC7, pSheet->m_independent);
	SetDlgItemText(IDC_STATIC8, pSheet->m_dependent);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}



