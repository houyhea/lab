#ifndef _M8PUSHBOXCELL_H
#define _M8PUSHBOXCELL_H

#include <mzfc_inc.h>
#include <mzfc\ImagingHelper.h>
#include "utils.h"
class M8PushBoxCell: public UiPicture2
{
public:
	M8PushBoxCell(void);
	virtual ~M8PushBoxCell(void);

    ImagingHelper m_cellIMGs[2];
	int m_row;
	int m_col;

};

#endif