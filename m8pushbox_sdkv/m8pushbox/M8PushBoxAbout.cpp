#include "M8PushBoxAbout.h"

#include "global.h"

// 按钮控件的ID
#define MZ_IDC_RETURNBTN  101




MZ_IMPLEMENT_DYNAMIC(M8PushBoxAbout)

M8PushBoxAbout::M8PushBoxAbout(void)
{
}

M8PushBoxAbout::~M8PushBoxAbout(void)
{
}

BOOL M8PushBoxAbout::OnInitDialog()
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

    m_pic_bgHelper.LoadImage(GetFullPath(PUSHBOX_ABOUT_BG), true, true, false);
    m_pic_bg.SetImage(&m_pic_bgHelper);
    m_pic_bg.SetPos(0, 0, 480, 720);
    m_pic_bg.SetDragMode(UI_DRAGMODE_FIXED);
    m_bg.AddChild(&m_pic_bg);
	AddUiWin(&m_bg);

	m_pic_btnHelper[0].LoadImage(GetFullPath(PUSHBOX_ABOUT_RETURN),true,true,true);
	m_pic_btnHelper[1].LoadImage(GetFullPath(PUSHBOX_ABOUT_RETURNH),true,true,true);


	m_returnBtn.SetID(MZ_IDC_RETURNBTN);
	m_returnBtn.SetImage_Normal(&m_pic_btnHelper[0]);
	m_returnBtn.SetImage_Pressed(&m_pic_btnHelper[1]);
	m_returnBtn.SetPos(140,610,197,55);
	m_returnBtn.SetButtonType(MZC_BUTTON_NONE);
	m_returnBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_returnBtn.SwapImageZOrder(true);
    m_returnBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_returnBtn);
	return TRUE;
}
void M8PushBoxAbout::OnMzCommand(WPARAM wParam, LPARAM lParam)
{
    UINT_PTR id = LOWORD(wParam);
    switch(id)
    {
    case MZ_IDC_RETURNBTN:
      {
		  this->EndModal(0);
      }
      break;
    }
}
LRESULT M8PushBoxAbout::MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam)
{
   

    return CMzWndEx::MzDefWndProc(message, wParam, lParam);
}



void M8PushBoxAbout::OnLButtonDown(UINT fwKeys, int xPos, int yPos)
{
	CMzWndEx::OnLButtonDown(fwKeys,xPos,yPos);
}

void M8PushBoxAbout::OnMouseMove(UINT fwKeys, int xPos, int yPos)
{
    
	CMzWndEx::OnMouseMove(fwKeys,xPos,yPos);

}

void M8PushBoxAbout::OnLButtonUp(UINT fwKeys, int xPos, int yPos)
{
	CMzWndEx::OnLButtonUp(fwKeys,xPos,yPos);
}