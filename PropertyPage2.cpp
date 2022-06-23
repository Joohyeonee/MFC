// PropertyPage2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage2.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"


// CPropertyPage2 대화 상자입니다.

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


// CPropertyPage2 메시지 처리기입니다.


BOOL CPropertyPage2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CPropertyPage2::OnBnClickedBringdata()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog dlg(TRUE/*Load*/, _T("csv"), NULL, OFN_HIDEREADONLY,
		_T("csv Files(*.csv)|*.csv|All Files (*.*)|*.*|"));

	dlg.DoModal();
	m_strPathName = dlg.GetPathName();
	SetDlgItemText(IDC_FILEPATH, m_strPathName);
}




LRESULT CPropertyPage2::OnWizardNext()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_strPathName.IsEmpty()) {
		AfxMessageBox(_T("데이터를 선택하지 않았습니다"));
		return -1;
	}
	SetModified(TRUE);
	return CPropertyPage::OnWizardNext();
}


BOOL CPropertyPage2::OnSetActive()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CPropSheet* pSheet1 = (CPropSheet*)GetParentSheet();
	pSheet1->SetWizardButtons(PSWIZB_NEXT | PSWIZB_BACK);

	return CPropertyPage::OnSetActive();
}
