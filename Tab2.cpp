// Tab2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Wizard.h"
#include "Tab2.h"
#include "afxdialogex.h"
#include "resource.h"


// CTab2 대화 상자입니다.

IMPLEMENT_DYNAMIC(CTab2, CDialogEx)

CTab2::CTab2(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB2, pParent)
{

}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ACTIVE, m_active);
	DDX_Control(pDX, IDC_LAYER1_FUNCTION, m_layer1Active);
	DDX_Control(pDX, IDC_LAYER2_FUNCTION, m_layer2Active);
	DDX_Control(pDX, IDC_N_LAYER, m_nHidden);
	DDX_Control(pDX, IDC_LAYER3_FUNCTION, m_layer3Active);
	DDX_Control(pDX, IDC_LAYER4_FUNCTION, m_layer4Active);
	DDX_Control(pDX, IDC_LAYER5_FUNCTION, m_layer5Active);
	DDX_Control(pDX, IDC_LAYER6_FUNCTION, m_layer6Active);
	DDX_Control(pDX, IDC_LAYER7_FUNCTION, m_layerActive7);
	DDX_Control(pDX, IDC_LAYER8_FUNCTION, m_layerActive8);
	DDX_Control(pDX, IDC_LAYER9_FUNCTION, m_layer9Active);
	DDX_Control(pDX, IDC_LAYER10_FUNCTION, m_layerActive10);
}


BEGIN_MESSAGE_MAP(CTab2, CDialogEx)
	ON_CBN_SELENDOK(IDC_ACTIVE, &CTab2::OnCbnSelendokActive)
	ON_CBN_SELENDOK(IDC_N_LAYER, &CTab2::OnCbnSelendokNLayer)
END_MESSAGE_MAP()


// CTab2 메시지 처리기입니다.



void CTab2::OnCbnSelendokActive()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_layer1Active.GetLBText(m_layer1Active.GetCurSel(), m_layer1Active1);
}


void CTab2::OnCbnSelendokNLayer()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nHidden.GetLBText(m_nHidden.GetCurSel(), str_nHidden);
	int num = _ttoi(str_nHidden);
	int i = num;

	for (int i = 1026; i < 1066; i += 4) {
		SetDlgItemText(i, _T("24"));
	}

	SetDlgItemText(IDC_N_LAYER, _T("2"));

	
	for (i = 4 * i + 1026; i < 1066; i++) {
		GetDlgItem(i)->ShowWindow(SW_HIDE);
	}

	int j = num;
	for (int j = 1026; j < 4 * num + 1026; j++) {
		GetDlgItem(j)->ShowWindow(SW_SHOW);
	}
}


BOOL CTab2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	int i = 2;
	for (i = 4 * i + 1026; i < 1066; i++) {
		GetDlgItem(i)->ShowWindow(SW_HIDE);
	}

	m_active.AddString(_T("Linear"));
	m_active.AddString(_T("Tanh"));
	m_active.AddString(_T("Sigmoid"));
	m_active.AddString(_T("ReLU"));
	m_active.AddString(_T("Leaky ReLU"));
	///m_active.SetCurSel(1);

	m_layer1Active.AddString(_T("ReLU"));
	m_layer1Active.SetCurSel(0);
	m_layer2Active.AddString(_T("ReLU"));
	m_layer2Active.SetCurSel(0);
	m_layer3Active.AddString(_T("ReLU"));
	m_layer3Active.SetCurSel(0);
	m_layer4Active.AddString(_T("ReLU"));
	m_layer4Active.SetCurSel(0);
	m_layer5Active.AddString(_T("ReLU"));
	m_layer5Active.SetCurSel(0);
	m_layer6Active.AddString(_T("ReLU"));
	m_layer6Active.SetCurSel(0);
	m_layerActive7.AddString(_T("ReLU"));
	m_layerActive7.SetCurSel(0);
	m_layerActive8.AddString(_T("ReLU"));
	m_layerActive8.SetCurSel(0);
	m_layer9Active.AddString(_T("ReLU"));
	m_layer9Active.SetCurSel(0);
	m_layerActive10.SetCurSel(0);
	m_layerActive10.AddString(_T("ReLU"));

	
	for (int i = 1; i < 11; i++) {
		CString str;
		str.Format(_T("%d"), i);
		m_nHidden.AddString(str);
	}
	m_nHidden.SetCurSel(1);

	
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


