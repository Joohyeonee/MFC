
// WizardView.cpp : CWizardView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CWizardView 생성/소멸

CWizardView::CWizardView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWizardView::~CWizardView()
{
}

BOOL CWizardView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWizardView 그리기

void CWizardView::OnDraw(CDC* pDC)
{
	CWizardDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect(&rect);

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CWizardView 진단

#ifdef _DEBUG
void CWizardView::AssertValid() const
{
	CView::AssertValid();
}

void CWizardView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWizardDoc* CWizardView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWizardDoc)));
	return (CWizardDoc*)m_pDocument;
}
#endif //_DEBUG


// CWizardView 메시지 처리기


void CWizardView::OnWizard()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

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
		dc.DrawText(_T("사용자가 설정한 옵션은 다음과 같습니다."), -1, &rect0, DT_LEFT);
		dc.DrawText(_T("학습 환경: \n\n학습 알고리즘: \n\n은닉층 개수: \n\n최대 Episode: \n\n학습률: \n\n할인율: \n\n종속변수: \n\n독립변수: ")
			, -1, &rect1, DT_LEFT);
		dc.DrawText(_T("예측 모델 환경\n\n")+sheet.m_algorithm+_T("\n\n")+sheet.m_nHidden+_T("\n\n")+sheet.m_episode+_T("\n\n")
			+sheet.m_learnRate+_T("\n\n")+sheet.m_discountRate+_T("\n\n")
			+sheet.m_dependent+_T("\n\n")+sheet.m_independent, -1, &rect2, DT_LEFT);
	}
	
}
