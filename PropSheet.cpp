// PropSheet.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "PropertyPage1.h"
#include "PropertyPage2.h"
#include "Wizard.h"
#include "PropSheet.h"


// CPropSheet

IMPLEMENT_DYNAMIC(CPropSheet, CPropertySheet)

CPropSheet::CPropSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	
}

CPropSheet::CPropSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

CPropSheet::CPropSheet()
{

}

CPropSheet::~CPropSheet()
{
	
}




BEGIN_MESSAGE_MAP(CPropSheet, CPropertySheet)
END_MESSAGE_MAP()


// CPropSheet �޽��� ó�����Դϴ�.

