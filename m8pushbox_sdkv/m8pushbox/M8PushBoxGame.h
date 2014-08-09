#ifndef _M8PUSHBOXGAME_WND_H
#define _M8PUSHBOXGAME_WND_H

// 包含需要用到的 MZFC 库头文件
#include <mzfc_inc.h>
#include <ShellNotifyMsg.h>
#include "utils.h"
#include "M8PushBoxCell.h"
#include "M8PushBoxLevelManager.h"
#include "M8PushBoxNumberBtn.h"
#include "M8PushBoxSuccess.h"
#include <vector>
using std::vector;


typedef enum _PbDirection
{
	PBUP,
	PBRIGHT,
	PBDOWN,
	PBLEFT,
}PbDirection;


class M8PushBoxGame :
	public CMzWndEx
{
	MZ_DECLARE_DYNAMIC(M8PushBoxGame);

public:
	M8PushBoxGame(void);
	virtual ~M8PushBoxGame(void);

	int m_totalLevel;
	int m_currentLevel;
	map m_currentMap;	

	M8PushBoxCell m_person;
	vector < M8PushBoxCell* > m_boxes;


protected:
	UiButton_Image m_leftBtn;
	UiButton_Image m_rightBtn;
	UiButton_Image m_menuBtn;

	ImagingHelper m_leftBtnHelper[2];
	ImagingHelper m_rightBtnHelper[2];
	ImagingHelper m_menuBtnHelper[2];

	//过关图片
	UiPicture2 m_winPic;
	ImagingHelper m_winPicHelper;
	//通关图片
	UiPicture2 m_cPic;
	ImagingHelper m_cPicHelper;


	M8PushBoxNumberBtn m_levelNumber;

	M8PushBoxLevelManager m_levelMaker;
	UiCanvas m_canvas;
	ImagingHelper m_pic_bgHelper;


	//M8PushBoxSuccess m_succWnd;

	void SetLevel(int level);
	void ClearBoxes();
	void Move(PbDirection direction);
	void MoveBox(PbPoint boxPoint,PbPoint nextPoint,CellType currentMapType, CellType nextMapType);
	void MovePerson(PbPoint nextPoint,CellType currentMapType, CellType nextMapType);

	bool CheckWin();
	bool CheckBoxOnTarget(M8PushBoxCell* box);

	int m_moveOffset;//判断移动基数

	bool m_toutchLock;


protected:

	void NextLevel();
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