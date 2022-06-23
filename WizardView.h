
// WizardView.h : CWizardView Ŭ������ �������̽�
//
#include "WizardDoc.h"
#include "PropSheet.h"

#pragma once


class CWizardView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWizardView();
	DECLARE_DYNCREATE(CWizardView)

// Ư���Դϴ�.
public:
	void OnWizard();
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~CWizardView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
	CWizardDoc * GetDocument() const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
};

#ifndef _DEBUG  // WizardView.cpp�� ����� ����
inline CWizardDoc* CWizardView::GetDocument() const
   { return reinterpret_cast<CWizardDoc*>(m_pDocument); }
#endif

