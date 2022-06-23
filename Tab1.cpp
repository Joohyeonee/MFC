// Tab1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Wizard.h"
#include "Tab1.h"
#include "Tab2.h"
#include "afxdialogex.h"


// CTab1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTab1, CDialogEx)

CTab1::CTab1(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TAB1, pParent)
{
	
}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ALGORITHM, m_algorithm);
	DDX_Control(pDX, IDC_NORMALIZE, m_yesno1);
	DDX_Control(pDX, IDC_DISCOUNT_RATE, m_discount_factor);
	DDX_Control(pDX, IDC_LEARN_RATE, m_learn_rate);
}


BEGIN_MESSAGE_MAP(CTab1, CDialogEx)

	ON_CBN_SELENDOK(IDC_ALGORITHM, &CTab1::OnCbnSelendokAlgorithm)
END_MESSAGE_MAP()


// CTab1 �޽��� ó�����Դϴ�.


BOOL CTab1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_algorithm.AddString(_T("DQN"));
	m_yesno1.AddString(_T("��"));
	m_yesno1.AddString(_T("�ƴϿ�"));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}




void CTab1::OnCbnSelendokAlgorithm()
{
	// TODO: Add your control notification handler code here
	CTab2 tab2;

	

	SetDlgItemText(IDC_DISCOUNT_RATE, _T("0.99"));
	SetDlgItemText(IDC_LEARN_RATE, _T("0.001"));
	SetDlgItemText(IDC_EPSILON, _T("1.0"));
	SetDlgItemText(IDC_EPSILON_DEC, _T("0.999"));
	SetDlgItemText(IDC_EPSILON_MIN, _T("0.01"));
	SetDlgItemText(IDC_EPISODE, _T("50"));
	SetDlgItemText(IDC_STEP, _T("500"));
	SetDlgItemText(IDC_SIZE, _T("64"));
	SetDlgItemText(IDC_MEMORY, _T("2000"));
	SetDlgItemText(IDC_START_LEARN, _T("1000"));

	tab2.OnCbnSelendokNLayer();

}
