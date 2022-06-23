// PropertyPage2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage2.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"


// CPropertyPage2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyPage2, CPropertyPage)

CPropertyPage2::CPropertyPage2()
	: CPropertyPage(IDD_DIALOG2)
{

}

CPropertyPage2::~CPropertyPage2()
{
}

void CPropertyPage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPropertyPage2, CPropertyPage)
	ON_BN_CLICKED(IDC_BRINGDATA, &CPropertyPage2::OnBnClickedBringdata)
END_MESSAGE_MAP()


// CPropertyPage2 �޽��� ó�����Դϴ�.


BOOL CPropertyPage2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CPropertyPage2::OnBnClickedBringdata()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CFileDialog dlg(TRUE/*Load*/, _T("csv"), NULL, OFN_HIDEREADONLY,
		_T("csv Files(*.csv)|*.csv|All Files (*.*)|*.*|"));

	dlg.DoModal();
	m_strPathName = dlg.GetPathName();
	SetDlgItemText(IDC_FILEPATH, m_strPathName);
}




LRESULT CPropertyPage2::OnWizardNext()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (m_strPathName.IsEmpty()) {
		AfxMessageBox(_T("�����͸� �������� �ʾҽ��ϴ�"));
		return -1;
	}
	SetModified(TRUE);
	return CPropertyPage::OnWizardNext();
}


BOOL CPropertyPage2::OnSetActive()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CPropSheet* pSheet1 = (CPropSheet*)GetParentSheet();
	pSheet1->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
