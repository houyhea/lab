#ifndef _M8PUSHBOXHELP_WND_H
#define _M8PUSHBOXHELP_WND_H

// ������Ҫ�õ��� MZFC ��ͷ�ļ�
#include <mzfc_inc.h>
#include <ShellNotifyMsg.h>
#include "utils.h"
class M8PushBoxHelper :
	public CMzWndEx
{
	MZ_DECLARE_DYNAMIC(M8PushBoxHelper);

public:
	M8PushBoxHelper(void);
	virtual ~M8PushBoxHelper(void);
protected:
	UiWin m_bg;
	UiPicture2 m_pic_bg;
	ImagingHelper m_pic_bgHelper;

	UiButton_Image m_returnBtn;

	ImagingHelper m_pic_btnHelper[2];
protected:
	// ��ʼ������
	virtual BOOL OnInitDialog();

	// �������İ�������
	virtual void OnMzCommand(WPARAM wParam, LPARAM lParam);

	// ������Ϣ����
	virtual LRESULT MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam);


	virtual void OnLButtonDown(UINT fwKeys, int xPos, int yPos);
	virtual void OnMouseMove(UINT fwKeys, int xPos, int yPos);
	virtual void OnLButtonUp(UINT fwKeys, int xPos, int yPos);
};

#endif