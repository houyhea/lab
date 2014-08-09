#include "m8pushboxmainwnd.h"

// ����SDK�ṩ��Ӧ�ó����ࡰģ�塱CMzApp�������Լ���Ӧ�ó����࣬ÿ��M8���򶼱���
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
    //����ȷ���Լ���Ψһʵ��
    if (!iAmOnlyOne(m_MainWnd))
    {
        return FALSE;
    }
	waveOutGetVolume(0,&m_originVol);
	

	DWORD dwVolume = 0x55555555;// 0x0 ~ 0xFFFFFFFF

	waveOutSetVolume(0,  dwVolume);		

    // Init the COM relative library.
    CoInitializeEx(0, COINIT_MULTITHREADED);

    //�������ʼ��
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
