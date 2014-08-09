#include "M8PushBoxNumberBtn.h"
#include "mzfc\ConvertHelper.h" 
M8PushBoxNumberBtn::M8PushBoxNumberBtn(void)
{

}

M8PushBoxNumberBtn::~M8PushBoxNumberBtn(void)
{
}
void M8PushBoxNumberBtn::SetNumber(int number)
{
	if(number>999)
		number=999;
	if(number<0)
		number=0;

	m_number=number;
	m_dcCanvas.Create(42,23);
        RECT rc;
		rc.left=0;
		rc.right=42;
		rc.top=0;
		rc.bottom=23;

        HBRUSH hBrush = CreateSolidBrush(RGB(255,242,130));
        FillRect(m_dcCanvas.GetDC(), &rc, hBrush);
        DeleteObject(hBrush);
		
	BitBlt(m_dcCanvas.GetDC(),0,0,14,23,m_imgs[number/100].GetDC(), 0,0,SRCCOPY);
	BitBlt(m_dcCanvas.GetDC(),14,0,14,23,m_imgs[(number%100)/10].GetDC(), 0,0,SRCCOPY);
	BitBlt(m_dcCanvas.GetDC(),28,0,14,23,m_imgs[number%10].GetDC(), 0,0,SRCCOPY);

	Invalidate();
}

void M8PushBoxNumberBtn::Init(CMzString numPath)
{
	m_Path=numPath;
	for(int i=0;i<10;i++)
	{

		CMzString str;
		str=(char)i;
		str=Int2String(i,1);
		str=numPath+L"\\"+str+L".png";
		m_imgs[i].LoadImage(GetFullPath(str),true,true,true);
	}
}

