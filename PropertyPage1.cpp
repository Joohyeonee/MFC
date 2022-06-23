// PropertyPage1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage1.h"
#include "propertyPage2.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"


// CPropertyPage1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPropertyPage1, CPropertyPage)

CPropertyPage1::CPropertyPage1()
	: CPropertyPage(IDD_DIALOG1)
{
	
}

CPropertyPage1::~CPropertyPage1()
{
}

void CPropertyPage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GMS, m_gms);
	
}


BEGIN_MESSAGE_MAP(CPropertyPage1, CPropertyPage)
	ON_BN_CLICKED(IDC_OPENGMS, &CPropertyPage1::OnBnClickedOpengms)
END_MESSAGE_MAP()


// CPropertyPage1 �޽��� ó�����Դϴ�.



BOOL CPropertyPage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


BOOL CPropertyPage1::OnKillActive()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.


	return CPropertyPage::OnKillActive();
}



void CPropertyPage1::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CPropertyPage::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CPropertyPage1::OnBnClickedOpengms()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	CFileDialog dlg(TRUE/*Load*/, _T("gms"), NULL, OFN_HIDEREADONLY,
		_T("ECMiner Model File(*.gms)|*.gms|All Files (*.*)|*.*||"));

	dlg.DoModal();
	m_strPathName = dlg.GetPathName();
	SetDlgItemText(IDC_GMS, m_strPathName);

}


BOOL CPropertyPage1::OnSetActive()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CWnd* pSheet = GetParent();
	CWnd* pWnd1 = pSheet->GetDlgItem(ID_WIZBACK);
	pWnd1->EnableWindow(FALSE);

	CPropSheet* pSheet1 = (CPropSheet*)GetParentSheet();
	pSheet1->SetWizardButtons(PSWIZB_NEXT);
	
	return CPropertyPage::OnSetActive();
}


LRESULT CPropertyPage1::OnWizardNext()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (m_strPathName.IsEmpty()) {
		AfxMessageBox(_T("���� �������� �ʾҽ��ϴ�"));
		return -1;
	}
	SetModified(TRUE);
	return CPropertyPage::OnWizardNext();
}

