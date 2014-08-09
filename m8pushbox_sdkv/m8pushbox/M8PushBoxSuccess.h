#ifndef _M8PUSHBOXSUCCESS_H
#define _M8PUSHBOXSUCCESS_H

// ������Ҫ�õ��� MZFC ��ͷ�ļ�
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
	// ��ʼ������
	virtual BOOL OnInitDialog();

	// �������İ�������
	virtual void OnMzCommand(WPARAM wParam, LPARAM lParam);

	// ������Ϣ����
	virtual LRESULT MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam);

    virtual void OnTimer(UINT_PTR  nIDEvent);
	virtual void OnLButtonDown(UINT fwKeys, int xPos, int yPos);
	virtual void OnMouseMove(UINT fwKeys, int xPos, int yPos);
	virtual void OnLButtonUp(UINT fwKeys, int xPos, int yPos);
};

#endif
