#include "m8pushboxmainwnd.h"

// 利用SDK提供的应用程序类“模板”CMzApp派生出自己的应用程序类，每个M8程序都必须
class M8App: public CMzApp
{
    public:
       M8PushBoxMainWnd m_MainWnd;

        virtual BOOL Init();

        int Done();
		DWORD m_originVol;
};

BOOL M8App::Init()
{
    //首先确定自己是唯一实例
    if (!iAmOnlyOne(m_MainWnd))
    {
        return FALSE;
    }
	waveOutGetVolume(0,&m_originVol);
	

	DWORD dwVolume = 0x55555555;// 0x0 ~ 0xFFFFFFFF

	waveOutSetVolume(0,  dwVolume);		

    // Init the COM relative library.
    CoInitializeEx(0, COINIT_MULTITHREADED);

    //主界面初始化
    RECT rcWork = MzGetWorkArea();
    m_MainWnd.Create(rcWork.left, rcWork.top, RECT_WIDTH(rcWork), RECT_HEIGHT(rcWork), 0, 0, 0);
		  m_MainWnd.AnimateWindow(MZ_ANIMTYPE_ZOOM_IN,true);
		  m_MainWnd.Show();
    m_MainWnd.UpdateWindow();
    m_MainWnd.SetShellHomekeyReturnValue(SHK_RET_APPEXIT_SHELLTOP);

    //MzAutoMsgBoxEx(m_MainWnd.m_hWnd, APP_NAME, 3000);
    return TRUE;
}

int M8App::Done()
{
    SetScreenAutoOff();
	ShowMzTopBar();
	
	//waveOutSetVolume(0,  m_originVol);		
	waveOutSetVolume(0,  0xFFFFFFFF);		

    //RETAILMSG(true, (L"SetScreenAutoOff()\r\n"));
    return 0;
}

M8App MyApp;
