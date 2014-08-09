#include "M8PushBoxMainWnd.h"
#include "m8pushboxabout.h"
#include "M8PushBoxHelper.h"
#include "M8PushBoxGame.h"
#include "global.h"

#include "UsbNotifyApi.h"

// 按钮控件的ID
#define MZ_IDC_STARTBTN  101
#define MZ_IDC_ABOUTBTN  102
#define MZ_IDC_CLOSEBTN  103
#define MZ_WND_ABOUT	104
#define MZ_WND_GAME	105




MZ_IMPLEMENT_DYNAMIC(M8PushBoxMainWnd)

M8PushBoxMainWnd::M8PushBoxMainWnd(void)
{
	g_iUsbNotifyMsg=0;
}

M8PushBoxMainWnd::~M8PushBoxMainWnd(void)
{
}

BOOL M8PushBoxMainWnd::OnInitDialog()
{
	// 记住在每个CMzWndEx的派生类里，只要你重写这个初始化方法，都必须要先调用下面这行代码！
    if (!CMzWndEx::OnInitDialog())
    {
        return FALSE;
    }
	
	g_iUsbNotifyMsg = RegisterUsbNotifyMsg();//注册USB中断事件

	HideMzTopBar();
	SetBgColor(0x000000);
	
    //背景
	SetWindowPos(this->m_hWnd,0,0,480,720);
    m_bg.SetPos(0,0, 480, 720);
    m_bg.RemoveAllChildren();

	CMzString s;
	
    m_pic_bgHelper.LoadImage(GetFullPath(PUSHBOX_MAIN_BG), true, true, false);
    m_pic_bg.SetImage(&m_pic_bgHelper);
    m_pic_bg.SetPos(0, 0, 480, 720);
    m_pic_bg.SetDragMode(UI_DRAGMODE_FIXED);
    m_bg.AddChild(&m_pic_bg);
	AddUiWin(&m_bg);

	m_pic_btnHelper[0][0].LoadImage(GetFullPath(PUSHBOX_MAIN_START),true,true,false);
	m_pic_btnHelper[0][1].LoadImage(GetFullPath(PUSHBOX_MAIN_STARTH),true,true,false);
	m_pic_btnHelper[1][0].LoadImage(GetFullPath(PUSHBOX_MAIN_ABOUT),true,true,false);
	m_pic_btnHelper[1][1].LoadImage(GetFullPath(PUSHBOX_MAIN_ABOUTH),true,true,false);
	m_pic_btnHelper[2][0].LoadImage(GetFullPath(PUSHBOX_MAIN_CLOSE),true,true,false);
	m_pic_btnHelper[2][1].LoadImage(GetFullPath(PUSHBOX_MAIN_CLOSEH),true,true,false);


	m_startBtn.SetID(MZ_IDC_STARTBTN);
	m_startBtn.SetImage_Normal(&m_pic_btnHelper[0][0]);
	m_startBtn.SetImage_Pressed(&m_pic_btnHelper[0][1]);
	m_startBtn.SetPos(140,490,197,55);
	m_startBtn.SetButtonType(MZC_BUTTON_NONE);
	m_startBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_startBtn.SwapImageZOrder(true);
    m_startBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_startBtn);

	m_aboutBtn.SetID(MZ_IDC_ABOUTBTN);
	m_aboutBtn.SetImage_Normal(&m_pic_btnHelper[1][0]);
	m_aboutBtn.SetImage_Pressed(&m_pic_btnHelper[1][1]);
	m_aboutBtn.SetPos(140,552,197,55);
	m_aboutBtn.SetButtonType(MZC_BUTTON_NONE);
	m_aboutBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_aboutBtn.SwapImageZOrder(true);
    m_aboutBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_aboutBtn);

	m_closeBtn.SetID(MZ_IDC_CLOSEBTN);
	m_closeBtn.SetImage_Normal(&m_pic_btnHelper[2][0]);
	m_closeBtn.SetImage_Pressed(&m_pic_btnHelper[2][1]);
	m_closeBtn.SetPos(140,614,197,55);
	m_closeBtn.SetButtonType(MZC_BUTTON_NONE);
	m_closeBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_closeBtn.SwapImageZOrder(true);
    m_closeBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_closeBtn);

	return TRUE;
}

void M8PushBoxMainWnd::OnMzCommand(WPARAM wParam, LPARAM lParam)
{
    UINT_PTR id = LOWORD(wParam);
    switch(id)
    {
    case MZ_IDC_STARTBTN:
      {
		  M8PushBoxGame gamedlg;
		  gamedlg.Create(0,0,480,720,m_hWnd,MZ_WND_GAME,WS_POPUP);
		  gamedlg.SetAnimateType_Hide(MZ_ANIMTYPE_SCROLL_LEFT_TO_RIGHT_PUSH);
		  gamedlg.SetAnimateType_Show(MZ_ANIMTYPE_SCROLL_RIGHT_TO_LEFT_PUSH);
		  gamedlg.DoModal();
		  
      }
      break;
    case MZ_IDC_ABOUTBTN:
      {
		  M8PushBoxAbout aboutdlg;
		  aboutdlg.Create(0,0,480,720,m_hWnd,MZ_WND_ABOUT,WS_POPUP);
		  aboutdlg.SetAnimateType_Hide(MZ_ANIMTYPE_SCROLL_LEFT_TO_RIGHT_PUSH);
		  aboutdlg.SetAnimateType_Show(MZ_ANIMTYPE_SCROLL_RIGHT_TO_LEFT_PUSH);
		  aboutdlg.DoModal();
			  
			
		  
      }
      break;
     case MZ_IDC_CLOSEBTN:
      {
		   if(1 == MzMessageBoxEx(m_hWnd, L"确定要退出?", L"退出", MB_YESNO, false))
		   {
			     //AnimateWindow(MZ_ANIMTYPE_ZOOM_OUT,false);
				 exit(0);
				//PostQuitMessage(0);
		   }
      }
      break;
   }
}
	LRESULT M8PushBoxMainWnd::MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam)
	{
		if(message == g_iUsbNotifyMsg)
		{
			INT iEvenType = (INT)wParam;
			//处理该事件
			switch(iEvenType)
			{
			case USB_MASSSTORAGE_ATTACH://如果有USB链接
				exit(0);
				
			default:
				break;
			}
			
			
		}

    return CMzWndEx::MzDefWndProc(message, wParam, lParam);
}



void M8PushBoxMainWnd::OnLButtonDown(UINT fwKeys, int xPos, int yPos)
{
	CMzWndEx::OnLButtonDown(fwKeys,xPos,yPos);
}

void M8PushBoxMainWnd::OnMouseMove(UINT fwKeys, int xPos, int yPos)
{
    
	CMzWndEx::OnMouseMove(fwKeys,xPos,yPos);

}

void M8PushBoxMainWnd::OnLButtonUp(UINT fwKeys, int xPos, int yPos)
{
	CMzWndEx::OnLButtonUp(fwKeys,xPos,yPos);
}
//实例唯一性判断
bool iAmOnlyOne(M8PushBoxMainWnd &Wnd)
{
    //检测是否已经有另外的实例在运行中:
    BOOL bFound = FALSE;
    HANDLE hMutexOneInstantance = CreateMutex(NULL, true, Wnd.m_pwszM8PushBoxMainWndClassName); 
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        bFound = TRUE;
    }
    if (hMutexOneInstantance)
    {
        ReleaseMutex(hMutexOneInstantance);
    }

    //激活已经在运行的实例的窗口
    if (bFound == TRUE)
    {
        HWND pwndFirst = FindWindow(Wnd.m_pwszM8PushBoxMainWndClassName, (LPCTSTR)NULL); 
        if (pwndFirst)
        {
            if (!IsWindowVisible(pwndFirst))
            {
                ShowWindow(pwndFirst, SW_SHOW);
            }
            SetForegroundWindow(pwndFirst);
        }
    }
    return !bFound;
}

