#ifndef _M8PUSHBOX_WND_H
#define _M8PUSHBOX_WND_H

// ������Ҫ�õ��� MZFC ��ͷ�ļ�
#include <mzfc_inc.h>
#include <ShellNotifyMsg.h>
#include "utils.h"
class M8PushBoxMainWnd :
	public CMzWndEx
{
	MZ_DECLARE_DYNAMIC(M8PushBoxMainWnd);

public:
	M8PushBoxMainWnd(void);
	virtual ~M8PushBoxMainWnd(void);
protected:
	UiWin m_bg;
	UiPicture2 m_pic_bg;
	ImagingHelper m_pic_bgHelper;

	UiButton_Image m_startBtn;
	UiButton_Image m_aboutBtn;
	UiButton_Image m_closeBtn;

	//UiPicture2 m_pic_btn[3][2];
	ImagingHelper m_pic_btnHelper[3][2];

	UINT	m_mkeyMsg;


	INT g_iUsbNotifyMsg ;	//USB�ж��¼�
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
bool iAmOnlyOne(M8PushBoxMainWnd &Wnd); // ʵ��Ψһ���ж�

#endif