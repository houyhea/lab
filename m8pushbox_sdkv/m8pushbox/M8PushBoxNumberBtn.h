#ifndef _M8PUSHBOXNUMBERBTN_H
#define _M8PUSHBOXNUMBERBTN_H

#include <mzfc_inc.h>
#include <mzfc\ImagingHelper.h>
#include "utils.h"

class M8PushBoxNumberBtn :
	public UiCanvas
{
public:
	M8PushBoxNumberBtn(void);
	virtual ~M8PushBoxNumberBtn(void);

	CMzString m_Path;
	void Init(CMzString numPath);
	void SetNumber(int number);
	ImagingHelper m_imgs[10];
protected:
		int m_number;
};

#endif