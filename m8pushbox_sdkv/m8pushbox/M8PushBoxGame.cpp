#include "M8PushBoxGame.h"
#include "M8PushBoxResumeWnd.h"


#include "global.h"

//ID
#define MZ_IDC_GAME_BG_CANVAS  101
#define MZ_IDC_GAME_LEFTBTN  102
#define MZ_IDC_GAME_RIGHTBTN  103
#define MZ_IDC_GAME_MENUBTN  104
#define MZ_IDC_GAME_WND_RESUME  105
#define MZ_IDC_GAME_LEVELNUMBER  106
#define MZ_IDC_GAME_SUCC  107
#define IDC_WIN_PIC 108
#define IDC_CLEAR_PIC 109

#define TIMER_OK 109


MZ_IMPLEMENT_DYNAMIC(M8PushBoxGame)

M8PushBoxGame::M8PushBoxGame(void)
{
	m_currentLevel=1;
	m_moveOffset=50;
	m_toutchLock=false;
}

M8PushBoxGame::~M8PushBoxGame(void)
{
	ClearBoxes();
}

BOOL M8PushBoxGame::OnInitDialog()
{
	// 记住在每个CMzWndEx的派生类里，只要你重写这个初始化方法，都必须要先调用下面这行代码！
	if (!CMzWndEx::OnInitDialog())
	{
		return FALSE;
	}

	m_totalLevel=m_levelMaker.m_totalLevelCnt;



	

	m_leftBtnHelper[0].LoadImage(GetFullPath(PUSHBOX_GAME_LEFTBTN), true, true, true);
	m_leftBtnHelper[1].LoadImage(GetFullPath(PUSHBOX_GAME_LEFTBTNH), true, true, true);

	m_rightBtnHelper[0].LoadImage(GetFullPath(PUSHBOX_GAME_RIGHTBTN), true, true, true);
	m_rightBtnHelper[1].LoadImage(GetFullPath(PUSHBOX_GAME_RIGHTBTNH), true, true, true);

	m_menuBtnHelper[0].LoadImage(GetFullPath(PUSHBOX_GAME_MENUBTN), true, true, true);
	m_menuBtnHelper[1].LoadImage(GetFullPath(PUSHBOX_GAME_MENUBTNH), true, true, true);

	m_leftBtn.SetID(MZ_IDC_GAME_LEFTBTN);
	m_leftBtn.SetPos(44,6,64,25);
	m_leftBtn.SetImage_Normal(&m_leftBtnHelper[0]);
	m_leftBtn.SetImage_Pressed(&m_leftBtnHelper[1]);
	m_leftBtn.SetButtonType(MZC_BUTTON_NONE);
	m_leftBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_leftBtn.SwapImageZOrder(true);
	m_leftBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_leftBtn);

	m_rightBtn.SetID(MZ_IDC_GAME_RIGHTBTN);
	m_rightBtn.SetPos(368,6,64,25);
	m_rightBtn.SetImage_Normal(&m_rightBtnHelper[0]);
	m_rightBtn.SetImage_Pressed(&m_rightBtnHelper[1]);
	m_rightBtn.SetButtonType(MZC_BUTTON_NONE);
	m_rightBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_rightBtn.SwapImageZOrder(true);
	m_rightBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_rightBtn);

	m_menuBtn.SetID(MZ_IDC_GAME_MENUBTN);
	m_menuBtn.SetPos(188,688,111,31);
	m_menuBtn.SetImage_Normal(&m_menuBtnHelper[0]);
	m_menuBtn.SetImage_Pressed(&m_menuBtnHelper[1]);
	m_menuBtn.SetButtonType(MZC_BUTTON_NONE);
	m_menuBtn.SetButtonMode(UI_BUTTON_IMAGE_MODE_NORMAL);
	m_menuBtn.SwapImageZOrder(true);
	m_menuBtn.SetTextColor(RGB(255,255,255));
	AddUiWin(&m_menuBtn);
	
	m_levelNumber.SetID(MZ_IDC_GAME_LEVELNUMBER);
	m_levelNumber.SetPos(219,6,42,23);
	m_levelNumber.Init(PUSHBOX_GAME_NUMBER_PATH);
	AddUiWin(&m_levelNumber);

	SetLevel(m_currentLevel);


	m_winPicHelper.LoadImage(GetFullPath(PUSHBOX_TIP_SUCCESS),true,true,true);
	m_winPic.SetID(IDC_WIN_PIC);
	m_winPic.SetPos(0,-500,384,230);
	m_winPic.SetImage(&m_winPicHelper);
	AddUiWin(&m_winPic);

	m_cPicHelper.LoadImage(GetFullPath(PUSHBOX_TIP_CLEAR),true,true,true);
	m_cPic.SetID(IDC_CLEAR_PIC);
	m_cPic.SetPos(-500,0,384,623);
	m_cPic.SetImage(&m_cPicHelper);
	AddUiWin(&m_cPic);

	return TRUE;
}

void M8PushBoxGame::SetLevel(int level)
{
	map * tmap=m_levelMaker.GetLevel(level);

	this->RemoveUiWin(&m_canvas);
	this->RemoveUiWin(&m_person);

	this->RemoveUiWin(&m_leftBtn);
	this->RemoveUiWin(&m_rightBtn);
	this->RemoveUiWin(&m_menuBtn);
	this->RemoveUiWin(&m_levelNumber);
	this->RemoveUiWin(&m_winPic);
	this->RemoveUiWin(&m_cPic);

	for(int b=0;b<m_boxes.size();b++)
	{
		this->RemoveUiWin(m_boxes[b]);
	}
	ClearBoxes();

	m_currentMap=*tmap;

	SetBgColor(0x000000);

	//背景
	m_canvas.SetID(MZ_IDC_GAME_BG_CANVAS);
	m_canvas.SetPos(0,0,480,720);
	m_canvas.m_dcCanvas.Create(480,720);
	m_pic_bgHelper.LoadImage(GetFullPath(PUSHBOX_GAME_BG), true, true, false);
	AddUiWin(&m_canvas);
	BitBlt(m_canvas.m_dcCanvas.GetDC(),0,0,480,720,m_pic_bgHelper.GetDC(), 0,0,SRCCOPY);//先平铺一张背景

	//平铺永远不会动的墙和目标
	ImagingHelper imgHelper;
	for(int row=0;row<13;row++)
	{
		for(int col=0;col<8;col++)
		{

			if(m_currentMap.m_map[row][col]==WALL)
			{
				imgHelper.LoadImage(GetFullPath(PUSHBOX_GAME_WALL), true, true, false);
				BitBlt(m_canvas.m_dcCanvas.GetDC(),48+48*col,48+48*row,48,48,imgHelper.GetDC(), 0,0,SRCCOPY);

			}
			else if(m_currentMap.m_map[row][col]==TARGET)
			{
				imgHelper.LoadImage(GetFullPath(PUSHBOX_GAME_TARGET), true, true, false);
				BitBlt(m_canvas.m_dcCanvas.GetDC(),48+48*col,48+48*row,48,48,imgHelper.GetDC(), 0,0,SRCCOPY);

			}

		}
	}



	m_person.SetID(MZ_IDC_GAME_BG_CANVAS+m_person.m_row+m_person.m_col);
	m_person.m_cellIMGs[0].LoadImage(GetFullPath(PUSHBOX_GAME_PERSON), true, true, true);
	m_person.m_cellIMGs[1].LoadImage(GetFullPath(PUSHBOX_GAME_PERSONONTARGET), true, true, false);
	m_person.SetImage(&m_person.m_cellIMGs[0]);
	m_person.m_row=m_currentMap.person.row;
	m_person.m_col=m_currentMap.person.col;
	m_person.SetPos(48+48*m_person.m_col,48+48*m_person.m_row,48,48);
	AddUiWin(&m_person);

	for(int k=0;k<m_currentMap.boxes.size();k++)
	{
		M8PushBoxCell *cell=new M8PushBoxCell();

		cell->SetID(MZ_IDC_GAME_BG_CANVAS+20+m_currentMap.boxes[k].row+m_currentMap.boxes[k].col);
		cell->m_cellIMGs[0].LoadImage(GetFullPath(PUSHBOX_GAME_BOX), true, true, false);
		cell->m_cellIMGs[1].LoadImage(GetFullPath(PUSHBOX_GAME_BOXONTARGET), true, true, false);
		cell->m_row=m_currentMap.boxes[k].row;
		cell->m_col=m_currentMap.boxes[k].col;
		cell->SetPos(48+48*cell->m_col,48+48*cell->m_row,48,48);
		cell->SetImage(&cell->m_cellIMGs[0]);
		AddUiWin(cell);

		m_boxes.push_back(cell);

	}
	m_levelNumber.SetNumber(level);

	AddUiWin(&m_leftBtn);
	AddUiWin(&m_rightBtn);
	AddUiWin(&m_menuBtn);
	AddUiWin(&m_levelNumber);
	AddUiWin(&m_winPic);
	AddUiWin(&m_cPic);
	Invalidate();

}

void M8PushBoxGame::ClearBoxes()
{
	M8PushBoxCell* box;
	for(int i=0;i<m_boxes.size();i++)
	{
		box=m_boxes[i];
		delete box;
	}
	std::vector<M8PushBoxCell*>::iterator theIt;
	for(theIt=m_boxes.begin(); theIt!=m_boxes.end(); )   
	{   
		theIt=m_boxes.erase(theIt);


	}



}
void M8PushBoxGame::OnMzCommand(WPARAM wParam, LPARAM lParam)
{
	if(m_toutchLock)
		return;
	UINT_PTR id = LOWORD(wParam);
	switch(id)
	{
	case MZ_IDC_GAME_LEFTBTN:
		{
			if(m_currentLevel==1)
			{
				//第一关了，提示
				//MzMessageBoxEx(m_hWnd, L"已经是第一关了。", L"M8推箱子");
				MzAutoMsgBoxEx(m_hWnd, L"已经是第一关了。", 1000);
				return;
			}					
			m_currentLevel--;
			SetLevel(m_currentLevel);				
		}
		break;
	case MZ_IDC_GAME_RIGHTBTN:
		{
			if(m_currentLevel==m_totalLevel)
			{
				//最后一关，提示
				//MzMessageBoxEx(m_hWnd, L"已经是最后一关了。", L"M8推箱子");
				MzAutoMsgBoxEx(m_hWnd, L"已经是最后一关了。", 1000);
				return;
			}					
			m_currentLevel++;
			SetLevel(m_currentLevel);				
		}
		break;
	case MZ_IDC_GAME_MENUBTN:
		{
			M8PushBoxResumeWnd resumdlg;

			resumdlg.Create(0,0,480,720,m_hWnd,MZ_IDC_GAME_WND_RESUME,WS_POPUP);
			resumdlg.SetAnimateType_Hide(MZ_ANIMTYPE_SCROLL_TOP_TO_BOTTOM_PUSH);
			resumdlg.SetAnimateType_Show( MZ_ANIMTYPE_SCROLL_BOTTOM_TO_TOP_PUSH) ;
			int ret=resumdlg.DoModal();

			if(ret==2)//returnMENU
			{
				this->EndModal(0);
			}	


		}
		break;
	}
}
LRESULT M8PushBoxGame::MzDefWndProc(UINT message, WPARAM wParam, LPARAM lParam)
{


	return CMzWndEx::MzDefWndProc(message, wParam, lParam);
}



void M8PushBoxGame::OnLButtonDown(UINT fwKeys, int xPos, int yPos)
{
	if(m_toutchLock)
		return;
	POINT personPos;
	personPos.x=48+ m_person.m_col*48;
	personPos.y=48+m_person.m_row*48;
	
	//重玩本关
	if(xPos>160 && xPos<320
		&&  yPos>0 &&yPos<48)
	{
		if(1 == MzMessageBoxEx(m_hWnd, L"确定要重玩本关?", L"M8推箱子", MB_YESNO, false))
		{
			SetLevel(m_currentLevel);				
			return;
		}
	}
		
	if( yPos>48 && yPos<(720-48))
	{
		int h_diff=abs(xPos-personPos.x);
		int v_diff=abs(yPos-personPos.y);
		if(h_diff>v_diff)
		{

			//判断左右方向
			if((xPos-personPos.x)>m_moveOffset)  //右
			{
				Move(PBRIGHT);
				return;
			}
			else if((xPos-personPos.x)<-m_moveOffset)//左
			{
				Move(PBLEFT);
				return;
			}
			if((yPos-personPos.y)>m_moveOffset)	//下
			{
				Move(PBDOWN);
				return;
			}
			else if((yPos-personPos.y)<-m_moveOffset) //上
			{
				Move(PBUP);
				return;
			}	

		}
		else
		{
			if((yPos-personPos.y)>m_moveOffset)	//下
			{
				Move(PBDOWN);
				return;
			}
			else if((yPos-personPos.y)<-m_moveOffset) //上
			{
				Move(PBUP);
				return;
			}	
			//判断左右方向
			if((xPos-personPos.x)>m_moveOffset)  //右
			{
				Move(PBRIGHT);
				return;
			}
			else if((xPos-personPos.x)<-m_moveOffset)//左
			{
				Move(PBLEFT);
				return;
			}
		}
	}
	//CMzWndEx::OnLButtonDown(fwKeys,xPos,yPos);
}
//移动箱子
void M8PushBoxGame::MoveBox(PbPoint boxPoint,PbPoint nextPoint,CellType currentMapType, CellType nextMapType)
{
	M8PushBoxCell *box;
	box=NULL;

	for(int i=0;i<m_boxes.size();i++)
	{
		if(m_boxes[i]->m_row==boxPoint.row 
			&& m_boxes[i]->m_col==boxPoint.col)
		{
			box=m_boxes[i];
			break;
		}
	}
	if(box==NULL)
		return;
	//在移动前，判断一下箱子的下一个是不是空地，或者目标，只有这两种情况，箱子才能移动
	if(nextMapType==BLANK
		|| nextMapType==TARGET)
	{		
		if(nextMapType==BLANK)
		{
			PlaySound(GetFullPath(PUSHBOX_WAV_MOVE), NULL, SND_FILENAME | SND_ASYNC) ;//播放声音
		}
		else
		{
			PlaySound(GetFullPath(PUSHBOX_WAV_DEST), NULL, SND_FILENAME | SND_ASYNC) ;//播放声音
		}
		box->m_row=nextPoint.row;
		box->m_col=nextPoint.col;

		if(nextMapType==TARGET)
			box->SetImage(&box->m_cellIMGs[1]);
		else
			box->SetImage(&box->m_cellIMGs[0]);

		box->SetPos(48+48*box->m_col,48+48*box->m_row,48,48);
		box->Invalidate();

		//修改下一个地图状态
		if(nextMapType==TARGET)
			m_currentMap.m_map[nextPoint.row][nextPoint.col]=BOXONTARGET;
		else
			m_currentMap.m_map[nextPoint.row][nextPoint.col]=BOX;

		//修改当前位置地图状态
		if(currentMapType==BOXONTARGET)
			m_currentMap.m_map[boxPoint.row][boxPoint.col]=TARGET;
		else
			m_currentMap.m_map[boxPoint.row][boxPoint.col]=BLANK;
	}

}
void M8PushBoxGame::MovePerson(PbPoint nextPoint,CellType currentMapType, CellType nextMapType)
{
	PbPoint currentPoint;
	currentPoint.row=m_person.m_row;
	currentPoint.col=m_person.m_col;

	//移动人之前，需要判断人的下一个位置是不是空地，或者是不是目标，只有这两种情况，人才能移动
	if(nextMapType==BLANK
		|| nextMapType==TARGET)
	{
		//PlaySound(GetFullPath(PUSHBOX_WAV_MOVE), NULL, SND_FILENAME | SND_ASYNC) ;//播放声音
		m_person.m_row=nextPoint.row;
		m_person.m_col=nextPoint.col;

		if(nextMapType==TARGET || nextMapType==BOXONTARGET)
			m_person.SetImage(&m_person.m_cellIMGs[1]);
		else
			m_person.SetImage(&m_person.m_cellIMGs[0]);
		m_person.SetPos(48+48*m_person.m_col,48+48*m_person.m_row,48,48);
		m_person.Invalidate();

		//修改人移动的下一个节点的地图状态
		if(nextMapType==TARGET)
			m_currentMap.m_map[nextPoint.row][nextPoint.col]=PERSONONTARGET;
		else
			m_currentMap.m_map[nextPoint.row][nextPoint.col]=BLANK;

		//修改当前人的地图状态
		if(currentMapType==PERSONONTARGET)
			m_currentMap.m_map[currentPoint.row][currentPoint.col]=TARGET;
		else
			m_currentMap.m_map[currentPoint.row][currentPoint.col]=BLANK;
	}

}
void M8PushBoxGame::Move(PbDirection direction)
{
	PbPoint nextPoint,nextNextPoint;
	switch(direction)
	{
	case PBLEFT:
		//如果人不是在地图边缘
		if(m_person.m_col>0)
		{
			//下一个
			nextPoint.col=m_person.m_col-1;
			nextPoint.row=m_person.m_row;
			//下一个的下一个
			nextNextPoint.col=nextPoint.col-1;
			nextNextPoint.row=nextPoint.row;
			//只有当下一个的下一个不是边缘，而且下一个是箱子的时候，才可能需要推箱子。
			if(nextPoint.col>0
				&& (m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOX
				||m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOXONTARGET))
			{
				//移动箱子
				MoveBox(nextPoint,nextNextPoint,
					(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col],
					(CellType)m_currentMap.m_map[nextNextPoint.row][nextNextPoint.col]);
			}
			//移动人
			MovePerson(nextPoint,
				(CellType)m_currentMap.m_map[m_person.m_row][m_person.m_col],
				(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col]);
			
			CheckWin();
			UpdateWindow();
			m_canvas.Invalidate();

		}
		break;
	case PBRIGHT:
		//如果人不是在地图边缘
		if(m_person.m_col<7)
		{
			//下一个
			nextPoint.col=m_person.m_col+1;
			nextPoint.row=m_person.m_row;
			//下一个的下一个
			nextNextPoint.col=nextPoint.col+1;
			nextNextPoint.row=nextPoint.row;
			//只有当下一个的下一个不是边缘，而且下一个是箱子的时候，才可能需要推箱子。
			if(nextPoint.col<7
				&& (m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOX
				||m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOXONTARGET))
			{
				//移动箱子
				MoveBox(nextPoint,nextNextPoint,
					(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col],
					(CellType)m_currentMap.m_map[nextNextPoint.row][nextNextPoint.col]);
			}
			//移动人
			MovePerson(nextPoint,
				(CellType)m_currentMap.m_map[m_person.m_row][m_person.m_col],
				(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col]);

			CheckWin();
			UpdateWindow();
			m_canvas.Invalidate();

		}
		break;
	case PBUP:
		//如果人不是在地图边缘
		if(m_person.m_row>0)
		{
			//下一个
			nextPoint.col=m_person.m_col;
			nextPoint.row=m_person.m_row-1;
			//下一个的下一个
			nextNextPoint.col=nextPoint.col;
			nextNextPoint.row=nextPoint.row-1;
			//只有当下一个的下一个不是边缘，而且下一个是箱子的时候，才可能需要推箱子。
			if(nextPoint.row>0
				&& (m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOX
				||m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOXONTARGET))
			{
				//移动箱子
				MoveBox(nextPoint,nextNextPoint,
					(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col],
					(CellType)m_currentMap.m_map[nextNextPoint.row][nextNextPoint.col]);
			}
			//移动人
			MovePerson(nextPoint,
				(CellType)m_currentMap.m_map[m_person.m_row][m_person.m_col],
				(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col]);

			CheckWin();
			UpdateWindow();
			m_canvas.Invalidate();

		}
		break;
	case PBDOWN:
		//如果人不是在地图边缘
		if(m_person.m_row<12)
		{
			//下一个
			nextPoint.col=m_person.m_col;
			nextPoint.row=m_person.m_row+1;
			//下一个的下一个
			nextNextPoint.col=nextPoint.col;
			nextNextPoint.row=nextPoint.row+1;
			//只有当下一个的下一个不是边缘，而且下一个是箱子的时候，才可能需要推箱子。
			if(nextPoint.row<12
				&& (m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOX
				||m_currentMap.m_map[nextPoint.row][nextPoint.col]==BOXONTARGET))
			{
				//移动箱子
				MoveBox(nextPoint,nextNextPoint,
					(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col],
					(CellType)m_currentMap.m_map[nextNextPoint.row][nextNextPoint.col]);
			}
			//移动人
			MovePerson(nextPoint,
				(CellType)m_currentMap.m_map[m_person.m_row][m_person.m_col],
				(CellType)m_currentMap.m_map[nextPoint.row][nextPoint.col]);

			CheckWin();

			UpdateWindow();
			m_canvas.Invalidate();

		}
		break;

	}


}

void M8PushBoxGame::OnTimer(UINT_PTR nIDEvent)
{
	//过关处理
    if (nIDEvent == TIMER_OK)
    {
		NextLevel();
	}
}
void M8PushBoxGame::NextLevel()
{
	m_toutchLock=false;
	KillTimer(m_hWnd,TIMER_OK);
	//Invalidate();
	if(m_currentLevel==m_totalLevel)
	{
		m_cPic.SetPos(-500,0,384,623); 
		m_currentLevel++;
		SetLevel(m_currentLevel);	

	}
	else
	{
		m_winPic.SetPos(48,-545,384,230); 
		m_currentLevel++;
		SetLevel(m_currentLevel);	

	}
}
bool M8PushBoxGame::CheckWin()
{
	bool tag=false;
	for(int i=0;i< m_boxes.size();i++)
	{
		tag=CheckBoxOnTarget(m_boxes[i]);
		if(!tag)
			return false;
	}
	if(tag)
	{
		PlaySound(GetFullPath(PUSHBOX_WAV_SUCCESS), NULL, SND_FILENAME | SND_ASYNC) ;//播放声音
		m_toutchLock=true;
		if(m_currentLevel==m_totalLevel)
		{
			m_cPic.SetPos(48,48,384,623); 
			Invalidate();
			SetTimer(m_hWnd, TIMER_OK, 8000, NULL);			
		}	
		else
		{
			m_winPic.SetPos(48,245,384,230); 
			Invalidate();
			SetTimer(m_hWnd, TIMER_OK, 1000, NULL);			
		}	
	}

	return tag;
}
bool M8PushBoxGame::CheckBoxOnTarget(M8PushBoxCell* box)
{
	bool tag=false;

	for(int i=0;i<m_currentMap.targets.size();i++)
	{
		if(box->m_col==m_currentMap.targets[i].col
			&& box->m_row==m_currentMap.targets[i].row)
		{
			return true;
		}
		else		
			tag=false;
	}
	return tag;

}

void M8PushBoxGame::OnMouseMove(UINT fwKeys, int xPos, int yPos)
{
	if(m_toutchLock)
		return;

	CMzWndEx::OnMouseMove(fwKeys,xPos,yPos);

}

void M8PushBoxGame::OnLButtonUp(UINT fwKeys, int xPos, int yPos)
{
	if(m_toutchLock)
		return;
	CMzWndEx::OnLButtonUp(fwKeys,xPos,yPos);
}

