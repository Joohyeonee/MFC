
// WizardDoc.h : CWizardDoc Ŭ������ �������̽�
//


#pragma once


class CWizardDoc : public CDocument
{
protected: // serialization������ ��������ϴ�.
	CWizardDoc();
	DECLARE_DYNCREATE(CWizardDoc)

// Ư���Դϴ�.
public:
	afx_msg void OnWizard();
// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// �����Դϴ�.
public:
	virtual ~CWizardDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// �˻� ó���⿡ ���� �˻� �������� �����ϴ� ����� �Լ�
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
