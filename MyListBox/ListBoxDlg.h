// ListBoxDlg.h : header file
//

#if !defined(AFX_LISTBOXDLG_H__DD17DE74_4381_4C4C_AB15_DD4E55ACDD5B__INCLUDED_)
#define AFX_LISTBOXDLG_H__DD17DE74_4381_4C4C_AB15_DD4E55ACDD5B__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
#include "MyListBox.h"
/////////////////////////////////////////////////////////////////////////////
// CListBoxDlg dialog

class CListBoxDlg : public CDialog
{
// Construction
public:
	CListBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListBoxDlg)
	enum { IDD = IDD_LISTBOX_DIALOG };
	CListBox	m_listbox1;
	CButton	m_Btn;
	CMyListBox	m_ListBox;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft eMbedded Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBOXDLG_H__DD17DE74_4381_4C4C_AB15_DD4E55ACDD5B__INCLUDED_)
