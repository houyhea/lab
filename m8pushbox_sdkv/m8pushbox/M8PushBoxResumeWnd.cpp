
#include "M8PushBoxResumeWnd.h"

#include "global.h"

// 按钮控件的ID
#define MZ_IDC_RETURNGAMEBTN  101
#define MZ_IDC_RETURNMENUBTN  102




MZ_IMPLEMENT_DYNAMIC(M8PushBoxResumeWnd)

M8PushBoxResumeWnd::M8PushBoxResumeWnd(void)
{
}

M8PushBoxResumeWnd::~M8PushBoxResumeWnd(void)
{
}

BOOL M8PushBoxResumeWnd::OnInitDialog()
{
	// 记住在每个CMzWndEx的派生类里，只要你重写这个初始化方法，都必须要先调用下面这行代码！
    if (!CMzWndEx::OnInitDialog())
    {
        return FALSE;
    }
	SetBgColor(0x000000);
	
    //背景
    m_bg.SetPos(0,0, 480, 720);
    m_bg.RemoveAllChildren();

    m_pic_bgHelper.LoadImage(GetFullPath(PUSHBOX_RESUME_BG), true, true, false);
    m_pic_bg.SetImage(&m_pic_bgHelper);
    m_pic_bg.SetPos(0, 0, 480, 720);
    m_pic_bg.SetDragMode(UI_DRAGMODE_FIXED);
    m_bg.AddChild(&m_pic_bg);
	AddUiWin(&m_bg);

	m_pic_gameBtnHelper[0].LoadImage(GetFullPath(PUSHBOX_RESUME_RETURNGAMEBTN),true,true,false);
	m_pic_gameBtnHelper[1].LoadImage(GetFullPath(PUSHBOX_RESUME_RETURNGAMEBTNH),true,true,false);

	m_pic_menuBtnHelper[0].LoadImage(GetFullPath(PUSHBOX_RESUME_RETURNMENUBTN),true,true,false);
	m_pic_menuBtnHelper[1].LoadImage(GetFullPath(PUSHBOX_RESUME_RETURNMENUBTNH),true,true,false);


	m_returnGameBtn.SetID(MZ_IDC_RETURNGAMEBTN);
	m_returnGameBtn.SetImage_Normal(&m_pic_gameBtnHelper[0]);
	m_returnGameBtn.SetImage_Pressed(&m_pic_gameBtnHelper[1]);
	m_returnGameBtn.SetPos(148,328,197,55);
	m_returnGameBtn.SetButtonType(MZC_BUTTON_NONE);
	m_returnGameBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_returnGameBtn.SwapImageZOrder(true);
    m_returnGameBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_returnGameBtn);

	m_returnMenuBtn.SetID(MZ_IDC_RETURNMENUBTN);
	m_returnMenuBtn.SetImage_Normal(&m_pic_menuBtnHelper[0]);
	m_returnMenuBtn.SetImage_Pressed(&m_pic_menuBtnHelper[1]);
	m_returnMenuBtn.SetPos(148,390,197,55);
	m_returnMenuBtn.SetButtonType(MZC_BUTTON_NONE);
	m_returnMenuBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_returnMenuBtn.SwapImageZOrder(true);
    m_returnMenuBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_returnMenuBtn);

	return TRUE;
}
void M8PushBoxResumeWnd::OnMzCommand(WPARAM wParam, LPARAM lParam)
{
    UINT_PTR id = LOWORD(wParam);
    switch(id)
    {
    case MZ_IDC_RETURNGAMEBTN:
      {
		  this->EndModal(1);
      }
      break;
     case MZ_IDC_RETURNMENUBTN:
      {
		  this->EndModal(2);
      }
      break;
   }
}
LRESULT M8PushBoxResumeWnd::MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam)
{
   

    return CMzWndEx::MzDefWndProc(message, wParam, lParam);
}



void M8PushBoxResumeWnd::OnLButtonDown(UINT fwKeys, int xPos, int yPos)
{
	CMzWndEx::OnLButtonDown(fwKeys,xPos,yPos);
}

void M8PushBoxResumeWnd::OnMouseMove(UINT fwKeys, int xPos, int yPos)
{
    
	CMzWndEx::OnMouseMove(fwKeys,xPos,yPos);

}

void M8PushBoxResumeWnd::OnLButtonUp(UINT fwKeys, int xPos, int yPos)
{
	CMzWndEx::OnLButtonUp(fwKeys,xPos,yPos);
}
