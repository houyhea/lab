


#include "M8PushBoxSuccess.h"

#include "global.h"


#define TIMER_OK 102


MZ_IMPLEMENT_DYNAMIC(M8PushBoxSuccess)

M8PushBoxSuccess::M8PushBoxSuccess(void)
{
}

M8PushBoxSuccess::~M8PushBoxSuccess(void)
{
}
BOOL M8PushBoxSuccess::OnInitDialog()
{
	// 记住在每个CMzWndEx的派生类里，只要你重写这个初始化方法，都必须要先调用下面这行代码！
    if (!CMzWndEx::OnInitDialog())
    {
        return FALSE;
    }
	SetBgColor(0x000000);
	
    //背景
    m_bg.SetPos(0,0, 384, 230);
    m_bg.RemoveAllChildren();

    m_pic_bgHelper.LoadImage(GetFullPath(PUSHBOX_TIP_SUCCESS), true, true, true);
    m_pic_bg.SetImage(&m_pic_bgHelper);
    m_pic_bg.SetPos(0, 0, 384, 230);
    m_pic_bg.SetDragMode(UI_DRAGMODE_FIXED);
    m_bg.AddChild(&m_pic_bg);
	AddUiWin(&m_bg);

	//SetTimer(m_hWnd, TIMER_OK, 3000, NULL);
	return TRUE;
}

void M8PushBoxSuccess::OnTimer(UINT_PTR nIDEvent)
{
    if (nIDEvent == TIMER_OK)
    {
		this->EndModal(0);
    }
}
void M8PushBoxSuccess::OnMzCommand(WPARAM wParam, LPARAM lParam)
{
   
}
LRESULT M8PushBoxSuccess::MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam)
{
   

    return CMzWndEx::MzDefWndProc(message, wParam, lParam);
}



void M8PushBoxSuccess::OnLButtonDown(UINT fwKeys, int xPos, int yPos)
{
	this->EndModal(0);
	//CMzWndEx::OnLButtonDown(fwKeys,xPos,yPos);
}

void M8PushBoxSuccess::OnMouseMove(UINT fwKeys, int xPos, int yPos)
{
    
	CMzWndEx::OnMouseMove(fwKeys,xPos,yPos);

}

void M8PushBoxSuccess::OnLButtonUp(UINT fwKeys, int xPos, int yPos)
{
	CMzWndEx::OnLButtonUp(fwKeys,xPos,yPos);
}