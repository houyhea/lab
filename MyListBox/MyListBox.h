#if !defined(AFX_MYLISTBOX_H__AF9C3258_C52C_4C9B_B9DC_3BA8141E58EF__INCLUDED_)
#define AFX_MYLISTBOX_H__AF9C3258_C52C_4C9B_B9DC_3BA8141E58EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyListBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyListBox window
#define LISTBOX_HEIGHT		40
class CMyListBox : public CListBox
{
// Construction
public:
	CMyListBox();
	//int AddString
	int AddString(LPCTSTR lpszItem);
// Attributes
public:
	CFont myfont;
	CBitmap m_BackScreenBitmap;
	BITMAP bmpInfo;
// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListBox)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetHScroll();
	virtual ~CMyListBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListBox)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYLISTBOX_H__AF9C3258_C52C_4C9B_B9DC_3BA8141E58EF__INCLUDED_)
