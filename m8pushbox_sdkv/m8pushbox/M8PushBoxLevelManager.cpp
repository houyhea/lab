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
    
	/*���￪ʼ��ȡrcdata�Ĺؿ����ݣ���һ���ֽڱ�ʾ�ܹ�����Ȼ���ȥ16���ֽڲ��ã�
	Ȼ��ӵڵ�ַ00000010��ʼ���ǵ�һ�ص����ݣ��������ǵ�M8ֻ��ʾ8�У�����һ����һ���ֽڱ�ʾ�����Ժ���8�ֽڶ�����
	Ȼ��0000020��ʾ��һ�صĵ�2�����ݣ����ǵ�M8�ܹ���13�У�����ֱ����ַ000000d0����һ�����ݲ��ꣻ�Դ����ƣ����ž���
	��2�����ݡ�
	*/
	if (resbyte != NULL)
    {
		LPBYTE& ptr=(LPBYTE&)resbyte;

		char totalLevel=*ptr;//��ȡ�ؿ��ܹ���
		m_totalLevelCnt=totalLevel;

		ptr+=16;	//�ƶ�16�ֽ�
		
		map data;
		int i=0,j=0;
		int l=0;
		for(i=0;i<totalLevel*13;i++)//��
		{
			for(j=0;j<16;j++)//��
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
					
					break;//�����У���ȡ��һ��
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

//level��������1��ʾ��һ��
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

