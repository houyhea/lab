#include "M8PushBoxLevelManager.h"

M8PushBoxLevelManager::M8PushBoxLevelManager(void)
{
	LoadLevel();
}

M8PushBoxLevelManager::~M8PushBoxLevelManager(void)
{

}
void M8PushBoxLevelManager::LoadLevel(	)
{
	HMODULE hModule = MzGetInstanceHandle();
    HRSRC resinfo = FindResource(hModule, MAKEINTRESOURCE(IDR_RCDATA_LEVEL), RT_RCDATA);
    HGLOBAL resdata = LoadResource(hModule, resinfo);
    DWORD ressize = SizeofResource(hModule, resinfo);
    LPVOID resbyte = LPVOID(LockResource(resdata));
    
	/*这里开始读取rcdata的关卡数据，第一个字节表示总关数，然后过去16个字节不用，
	然后从第地址00000010开始，是第一关的数据，由于我们的M8只显示8列，所以一列用一个字节表示，所以后面8字节丢弃；
	然后0000020表示第一关的第2行数据，我们的M8总共有13行，所以直到地址000000d0，第一关数据才完；以此类推，接着就是
	第2关数据。
	*/
	if (resbyte != NULL)
    {
		LPBYTE& ptr=(LPBYTE&)resbyte;

		char totalLevel=*ptr;//读取关卡总关数
		m_totalLevelCnt=totalLevel;

		ptr+=16;	//移动16字节
		
		map data;
		int i=0,j=0;
		int l=0;
		for(i=0;i<totalLevel*13;i++)//行
		{
			for(j=0;j<16;j++)//列
			{
				int row=i%13;
				data.m_map[row][j]=(int)(*ptr);
				if(data.m_map[row][j]==BOX)
				{
					PbPoint p;
					p.col=j;
					p.row=row;
					data.boxes.push_back(p);
				}

				if(data.m_map[row][j]==TARGET)
				{
					PbPoint p;
					p.col=j;
					p.row=row;
					data.targets.push_back(p);
				}

				if(data.m_map[row][j]==PERSON)
				{
					data.person.col=j;
					data.person.row=row;
				}

				if(j>=7)
				{
					ptr+=8+1;
					
					break;//跳出列，读取下一行
				}
				else
				{
					ptr++;
				}
				
			}
			l++;
			if(l==13)
			{
				m_maps.push_back(data);
				
				std::vector<PbPoint>::iterator theIt;
				for(theIt=data.boxes.begin(); theIt!=data.boxes.end(); )   
				{   
					theIt=data.boxes.erase(theIt);
				}


				for(theIt=data.targets.begin(); theIt!=data.targets.end(); )   
				{   
					theIt=data.targets.erase(theIt);
				}

				l=0;
			}
		}


	}

}

//level：关数，1表示第一关
map* M8PushBoxLevelManager::GetLevel(int level)
{
	map* result=NULL;

	if (level > 0 && level <=m_totalLevelCnt)
    {
        result = &m_maps[level - 1];
    }
    else
    {
        result = &m_maps[0];
    }

    return result;
}

