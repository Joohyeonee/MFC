// PropertyPage1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Wizard.h"
#include "PropertyPage1.h"
#include "propertyPage2.h"
#include "afxdialogex.h"
#include "PropSheet.h"
#include "resource.h"


// CPropertyPage1 대화 상자입니다.

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


// CPropertyPage1 메시지 처리기입니다.



BOOL CPropertyPage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


BOOL CPropertyPage1::OnKillActive()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.


	return CPropertyPage::OnKillActive();
}



void CPropertyPage1::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CPropertyPage::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CPropertyPage1::OnBnClickedOpengms()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CFileDialog dlg(TRUE/*Load*/, _T("gms"), NULL, OFN_HIDEREADONLY,
		_T("ECMiner Model File(*.gms)|*.gms|All Files (*.*)|*.*||"));

	dlg.DoModal();
	m_strPathName = dlg.GetPathName();
	SetDlgItemText(IDC_GMS, m_strPathName);

}


BOOL CPropertyPage1::OnSetActive()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CWnd* pSheet = GetParent();
	CWnd* pWnd1 = pSheet->GetDlgItem(ID_WIZBACK);
	pWnd1->EnableWindow(FALSE);

	CPropSheet* pSheet1 = (CPropSheet*)GetParentSheet();
	pSheet1->SetWizardButtons(PSWIZB_NEXT);
	
	return CPropertyPage::OnSetActive();
}


LRESULT CPropertyPage1::OnWizardNext()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (m_strPathName.IsEmpty()) {
		AfxMessageBox(_T("모델을 선택하지 않았습니다"));
		return -1;
	}
	SetModified(TRUE);
	return CPropertyPage::OnWizardNext();
}

