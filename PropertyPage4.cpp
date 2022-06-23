// PropertyPage4.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage4.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"


// CPropertyPage4 ��ȭ �����Դϴ�.

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


// CPropertyPage4 �޽��� ó�����Դϴ�.




BOOL CPropertyPage4::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
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
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}




LRESULT CPropertyPage4::OnWizardNext()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CString str_dependent;
	CString str_independent;
	
	GetDlgItemText(IDC_DEPENDENT, str_dependent);
	GetDlgItemText(IDC_INDEPENDENT, str_independent);

	if (str_dependent.IsEmpty() || str_independent.IsEmpty()) {
		AfxMessageBox(_T("������ �������� �ʾҽ��ϴ�"));
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CPropSheet* pSheet = (CPropSheet*)GetParentSheet();
	pSheet->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
