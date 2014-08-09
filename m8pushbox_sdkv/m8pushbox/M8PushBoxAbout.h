#ifndef _M8PUSHBOXABOUT_WND_H
#define _M8PUSHBOXABOUT_WND_H

// 包含需要用到的 MZFC 库头文件
#include <mzfc_inc.h>
#include <ShellNotifyMsg.h>
#include "utils.h"
class M8PushBoxAbout :
	public CMzWndEx
{
	MZ_DECLARE_DYNAMIC(M8PushBoxAbout);

public:
	M8PushBoxAbout(void);
	virtual ~M8PushBoxAbout(void);
protected:
	UiWin m_bg;
	UiPicture2 m_pic_bg;
	ImagingHelper m_pic_bgHelper;

	UiButton_Image m_returnBtn;

	ImagingHelper m_pic_btnHelper[2];
protected:
	// 初始化窗体
	virtual BOOL OnInitDialog();

	// 工具栏的按键处理
	virtual void OnMzCommand(WPARAM wParam, LPARAM lParam);

	// 窗口消息处理
	virtual LRESULT MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam);


	virtual void OnLButtonDown(UINT fwKeys, int xPos, int yPos);
	virtual void OnMouseMove(UINT fwKeys, int xPos, int yPos);
	virtual void OnLButtonUp(UINT fwKeys, int xPos, int yPos);
};

#endif