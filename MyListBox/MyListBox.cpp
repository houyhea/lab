// MyListBox.cpp : implementation file
//

#include "stdafx.h"
//#include "ListBox.h"
#include "MyListBox.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyListBox

CMyListBox::CMyListBox()
{
	m_BackScreenBitmap.LoadBitmap(IDB_BITMAP1);
	m_BackScreenBitmap.GetBitmap(&bmpInfo);
	myfont.CreateFont(
            30,                        // nHeight
            0,                        // nWidth
            0,                        // nEscapement
            0,                        // nOrientation
            FW_BOLD,                // nWeight
            FALSE,                    // bItalic
            FALSE,                    // bUnderline
            0,                        // cStrikeOut
            ANSI_CHARSET,              // nCharSet
            OUT_DEFAULT_PRECIS,        // nOutPrecision
            CLIP_DEFAULT_PRECIS,      // nClipPrecision
            DEFAULT_QUALITY,          // nQuality
            DEFAULT_PITCH | FF_SWISS,
            _T("Arial")                    // nPitchAndFamily
            );  
}

CMyListBox::~CMyListBox()
{
}


BEGIN_MESSAGE_MAP(CMyListBox, CListBox)
	//{{AFX_MSG_MAP(CMyListBox)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListBox message handlers
//DEL BOOL CMyListBox::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
//DEL {
//DEL 	//dwStyle
//DEL 	return 
//DEL }

BOOL CMyListBox::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default	

#if 1
		pDC = GetDC();
		//CString d="ctlcolor";
		//MessageBox(d,NULL,MB_OK);
	for(int i = 0;i<GetCount();i++)
	{
		CRect eachrc;
		CBrush brush;
		CString str;
		GetItemRect(i,eachrc);
		
		CDC dcMemory;
		dcMemory.CreateCompatibleDC(pDC);


		// Select the bitmap into the in-memory DC
		CBitmap* pOldBitmap = dcMemory.SelectObject(&m_BackScreenBitmap);

		pDC->BitBlt(0, 0+i*eachrc.Height(), bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 0, 0, SRCCOPY);	
		pDC->SelectObject(pOldBitmap);

		//pDC->FillRect(eachrc,&brush);

		GetText(i,str);
		pDC->SetBkMode(TRANSPARENT);

		pDC->SelectObject(GetFont());
		pDC->SelectObject(&myfont);
		pDC->DrawText(str,&eachrc,DT_VCENTER | DT_SINGLELINE);

	}
#endif
	return true;//
	//return CListBox::OnEraseBkgnd(pDC);
}



HBRUSH CMyListBox::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	// TODO: Change any attributes of the DC here
	
#if 1
	pDC = GetDC();
	//MessageBox(_L"ctlcolor");
	//MessageBox(NULL,"ddd","ddd",MB_OK); 
	//CString d="ctlcolor";
	//MessageBox(d,NULL,MB_OK);
	if (nCtlColor == CTLCOLOR_LISTBOX)
	{
		for(int i = 0;i<GetCount();i++)
		{
			CRect eachrc;
			CBrush brush;
			CString str;
			GetItemRect(i,eachrc);
			
		
			CDC dcMemory;
			dcMemory.CreateCompatibleDC(pDC);
	
	
			// Select the bitmap into the in-memory DC
			CBitmap* pOldBitmap = dcMemory.SelectObject(&m_BackScreenBitmap);

			pDC->BitBlt(0, 0+i*eachrc.Height(), bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 0, 0, SRCCOPY);	
			pDC->SelectObject(pOldBitmap);

			//pDC->FillRect(eachrc,&brush);
			

			GetText(i,str);
			pDC->SetBkMode(TRANSPARENT);

			pDC->SelectObject(GetFont());
			pDC->SelectObject(&myfont);
			pDC->DrawText(str,&eachrc,DT_VCENTER | DT_SINGLELINE);
			//pDC->SetTextColor(RGB(165,120,12));
			//SetItemHeight(i,LISTBOX_HEIGHT);
		}
	}
#endif
	
	//
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	return  (HBRUSH)::GetStockObject(HOLLOW_BRUSH);
	return NULL;
}

//DEL BOOL CMyListBox::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
//DEL }


void CMyListBox::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	#if 1
	
	CDC* pDC;
	pDC = GetDC();
	//MessageBox(_L"ctlcolor");
	//MessageBox(NULL,"ddd","ddd",MB_OK); 
	//CString d="ctlcolor";
	//MessageBox(d,NULL,MB_OK);
	
		for(int i = 0;i<GetCount();i++)
		{
			CRect eachrc;
			CBrush brush;
			CString str;
			GetItemRect(i,eachrc);
			
			
			CDC dcMemory;
			dcMemory.CreateCompatibleDC(&dc);
	
	
			// Select the bitmap into the in-memory DC
			CBitmap* pOldBitmap = dcMemory.SelectObject(&m_BackScreenBitmap);
			
			dc.BitBlt(0, 0+i*eachrc.Height(), bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 0, 0, SRCCOPY);	
			dc.SelectObject(pOldBitmap);

			//pDC->FillRect(eachrc,&brush);
			

			GetText(i,str);
			dc.SetBkMode(TRANSPARENT);

			
			dc.SelectObject(&myfont);
			dc.DrawText(str,&eachrc,DT_VCENTER | DT_SINGLELINE);
			//dc.SetTextColor(RGB(165,120,12));
			//SetItemHeight(i,LISTBOX_HEIGHT);
		}
	
#endif
	
	//
	// TODO: Return a non-NULL brush if the parent's handler should not be called
	
	// Do not call CListBox::OnPaint() for painting messages
}



void CMyListBox::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	#if 1
	CDC * pDC = GetDC();
	
	
	//MessageBox(_L"ctlcolor");
	//MessageBox(NULL,"ddd","ddd",MB_OK); 
	//CString d="ctlcolor";
	//MessageBox(d,NULL,MB_OK);

		for(int i = 0;i<GetCount();i++)
		{
			CRect eachrc;
			CBrush brush;
			CString str;
			GetItemRect(i,eachrc);
			
			
			CDC dcMemory;
			dcMemory.CreateCompatibleDC(pDC);
	
	
			// Select the bitmap into the in-memory DC
			CBitmap* pOldBitmap = dcMemory.SelectObject(&m_BackScreenBitmap);

			pDC->BitBlt(0, 0+i*eachrc.Height(), bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 0, 0, SRCCOPY);	
			pDC->SelectObject(pOldBitmap);

			//pDC->FillRect(eachrc,&brush);
			

			GetText(i,str);
			pDC->SetBkMode(TRANSPARENT);

			pDC->SelectObject(GetFont());
			pDC->SelectObject(&myfont);
			pDC->DrawText(str,&eachrc,DT_VCENTER | DT_SINGLELINE);
			//pDC->SetTextColor(RGB(165,120,12));

		}



#endif
	//CListBox::OnLButtonDown(nFlags, point);
}

int CMyListBox::AddString(LPCTSTR lpszItem)
{
	int ret=CListBox::AddString(lpszItem);
	for(int i = 0;i<GetCount();i++)
	{
		SetItemHeight(i,LISTBOX_HEIGHT);
	}
	SetHScroll();
	return ret;
}

//根据ITEM的长度，设置横向滚动条
void CMyListBox::SetHScroll()
{
	
	CString str;
	CSize   sz;
	int     dx=0;
	CDC*    pDC = this->GetDC();
	for (int i=0;i < this->GetCount();i++)
	{
	  this->GetText( i, str );
	  sz = pDC->GetTextExtent(str);

	  if (sz.cx > dx)
		dx = sz.cx;
	}
	this->ReleaseDC(pDC);

	// Set the horizontal extent so every character of all strings 
	// can be scrolled to.
	this->SetHorizontalExtent(dx);
}

void CMyListBox::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	CString d="test";
	//MessageBox(d,NULL,MB_OK);
	CListBox::OnHScroll(nSBCode, nPos, pScrollBar);

}
