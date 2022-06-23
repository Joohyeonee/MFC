
// WizardView.h : CWizardView 클래스의 인터페이스
//
#include "WizardDoc.h"
#include "PropSheet.h"

#pragma once


class CWizardView : public CView
{
protected: // serialization에서만 만들어집니다.
	CWizardView();
	DECLARE_DYNCREATE(CWizardView)

// 특성입니다.
public:
	void OnWizard();
// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~CWizardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	CWizardDoc * GetDocument() const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
};

#ifndef _DEBUG  // WizardView.cpp의 디버그 버전
inline CWizardDoc* CWizardView::GetDocument() const
   { return reinterpret_cast<CWizardDoc*>(m_pDocument); }
#endif

