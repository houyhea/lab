// ListBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListBox.h"
#include "ListBoxDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
static BOOL ListBoxShow = FALSE;

/////////////////////////////////////////////////////////////////////////////
// CListBoxDlg dialog

CListBoxDlg::CListBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CListBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CListBoxDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CListBoxDlg)
	DDX_Control(pDX, IDC_LIST2, m_listbox1);
	DDX_Control(pDX, IDC_BUTTON1, m_Btn);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CListBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CListBoxDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListBoxDlg message handlers

BOOL CListBoxDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	CenterWindow(GetDesktopWindow());	// center to the hpc screen

	// TODO: Add extra initialization here
	
	/*
	m_ListBox.AddString(_T("I think this is a joke."));
	m_ListBox.AddString(_T("I love wsn."));
	m_ListBox.AddString(_T("check out for check in ."));
	
	m_ListBox.AddString(_T("This is a test string."));
	m_ListBox.AddString(_T("Go to someplace for happiness."));
	m_ListBox.AddString(_T("Do you really like playing ball."));
	m_ListBox.AddString(_T("Give you sun,get it away."));	
	*/
	  for (int i = 0; i < m_ListBox.GetCount(); i++)
	{
		m_ListBox.SetItemHeight(i,LISTBOX_HEIGHT);
	}

	m_ListBox.SetWindowPos(this,50,50,529,160,SWP_NOZORDER);


	//设置横向滚动条
	//m_ListBox.SetHScroll();
		m_ListBox.AddString(_T("Add a new string Toshen zhen Tiesfsdf @dgg.Go to hello yse hye bbubush yte.smine swindyw d."));	
	m_ListBox.SetHorizontalExtent(620);

	
	
	//m_listbox1.AddString(_T("Add a new string This is a test string.This is a test string.This is a test string."));	
	//m_listbox1.SetHorizontalExtent(220);


	//m_ListBox.ShowWindow(SW_HIDE);
	//m_ListBox.Create(WS_CHILD | WS_VISIBLE ,CRect(150,100,300,200),GetParent(),IDC_LIST1);
	return TRUE;  // return TRUE  unless you set the focus to a control
}



void CListBoxDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here

	if (!ListBoxShow)
	{

		m_ListBox.ShowWindow(SW_SHOWNA);
#if 1
		CDC *pdc;
		pdc = m_ListBox.GetDC();
		for(int i = 0;i<m_ListBox.GetCount();i++)
		{
			CRect eachrc;
			CBrush brush;
			CString str;
			m_ListBox.GetItemRect(i,eachrc);
			
#if 1
			switch(i)
			{
			case 0:
				brush.CreateSolidBrush(RGB(255,0,0));
				break;
			case 1:
				brush.CreateSolidBrush(RGB(0,255,0));
				break;
				
			case 2:
				brush.CreateSolidBrush(RGB(0,0,255));
				break;
			case 3:
				brush.CreateSolidBrush(RGB(255,0,255));
				break;
				
			default:
				break;
			}
			pdc->FillRect(eachrc,&brush);
#endif	
			m_ListBox.GetText(i,str);
			pdc->SetBkMode(TRANSPARENT);
			
			pdc->SelectObject(m_ListBox.GetFont());
			pdc->DrawText(str,&eachrc,DT_VCENTER | DT_SINGLELINE);
			
		}
#endif

		ListBoxShow = TRUE;
		//m_ListBox.Invalidate();
	}
	else
	{
		m_ListBox.ShowWindow(SW_HIDE);
		ListBoxShow = FALSE;
	}
}







void CListBoxDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	m_ListBox.AddString(_T("Add a new string This is a test string.This is a test string.This is a test string."));	
	m_listbox1.AddString(_T("Add a new string This is a test string.This is a test string.This is a test string."));	
		
	m_listbox1.AddString(_T("Add a new string This is a test string.This is a test string.This is a test string."));	
	m_listbox1.SetHorizontalExtent(820);

}

