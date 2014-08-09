#ifndef _M8PUSHBOXSUCCESS_H
#define _M8PUSHBOXSUCCESS_H

// 包含需要用到的 MZFC 库头文件
#include <mzfc_inc.h>
#include <ShellNotifyMsg.h>
#include "utils.h"
class M8PushBoxSuccess :
	public CMzWndEx
{
	MZ_DECLARE_DYNAMIC(M8PushBoxSuccess);

public:
	M8PushBoxSuccess(void);
	virtual ~M8PushBoxSuccess(void);
protected:
	UiWin m_bg;
	UiPicture2 m_pic_bg;
	ImagingHelper m_pic_bgHelper;

protected:
	// 初始化窗体
	virtual BOOL OnInitDialog();

	// 工具栏的按键处理
	virtual void OnMzCommand(WPARAM wParam, LPARAM lParam);

	// 窗口消息处理
	virtual LRESULT MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam);

    virtual void OnTimer(UINT_PTR  nIDEvent);
	virtual void OnLButtonDown(UINT fwKeys, int xPos, int yPos);
	virtual void OnMouseMove(UINT fwKeys, int xPos, int yPos);
	virtual void OnLButtonUp(UINT fwKeys, int xPos, int yPos);
};

#endif
