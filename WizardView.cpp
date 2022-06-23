
// WizardView.cpp : CWizardView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Wizard.h"
#endif

#include "WizardDoc.h"
#include "WizardView.h"
#include "PropSheet.h"
#include "PropertyPage1.h"
#include "PropertyPage2.h"
#include "PropertyPage3.h"
#include "PropertyPage4.h"
#include "PropertyPage5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWizardView

IMPLEMENT_DYNCREATE(CWizardView, CView)

BEGIN_MESSAGE_MAP(CWizardView, CView)
	ON_COMMAND(ID_WIZARD, &CWizardView::OnWizard)
END_MESSAGE_MAP()

// CWizardView ����/�Ҹ�

CWizardView::CWizardView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWizardView::~CWizardView()
{
}

BOOL CWizardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWizardView �׸���

void CWizardView::OnDraw(CDC* pDC)
{
	CWizardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWizardView ����

#ifdef _DEBUG
void CWizardView::AssertValid() const
{
	CView::AssertValid();
}

void CWizardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWizardDoc* CWizardView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWizardDoc)));
	return (CWizardDoc*)m_pDocument;
}
#endif //_DEBUG


// CWizardView �޽��� ó����


void CWizardView::OnWizard()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.

	CClientDC dc(this);
	CRect rect0(50, 150, 500, 500);
	CRect rect1(50, 200, 250, 700);
	CRect rect2(250, 200, 700, 700);
	CPropSheet sheet;

	CPropertyPage1 m_page1;
	CPropertyPage2 m_page2;
	CPropertyPage3 m_page3;
	CPropertyPage4 m_page4;
	CPropertyPage5 m_page5;

	sheet.AddPage(&m_page1);
	sheet.AddPage(&m_page2);
	sheet.AddPage(&m_page3);
	sheet.AddPage(&m_page4);
	sheet.AddPage(&m_page5);

	sheet.SetWizardMode();
	if (sheet.DoModal() == 12325) {
		dc.DrawText(_T("����ڰ� ������ �ɼ��� ������ �����ϴ�."), -1, &rect0, DT_LEFT);
		dc.DrawText(_T("�н� ȯ��: \n\n�н� �˰���: \n\n������ ����: \n\n�ִ� Episode: \n\n�н���: \n\n������: \n\n���Ӻ���: \n\n��������: ")
			, -1, &rect1, DT_LEFT);
		dc.DrawText(_T("���� �� ȯ��\n\n")+sheet.m_algorithm+_T("\n\n")+sheet.m_nHidden+_T("\n\n")+sheet.m_episode+_T("\n\n")
			+sheet.m_learnRate+_T("\n\n")+sheet.m_discountRate+_T("\n\n")
			+sheet.m_dependent+_T("\n\n")+sheet.m_independent, -1, &rect2, DT_LEFT);
	}
	
}
