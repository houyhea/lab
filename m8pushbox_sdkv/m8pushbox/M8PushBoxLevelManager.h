#ifndef _M8PUSHBOXLEVELMANAGER_H
#define _M8PUSHBOXLEVELMANAGER_H
#include <mzfc_inc.h>
#include <ReadWriteIni.h>
#include "resource.h"
#include "utils.h"
#include <vector>
using std::vector;

typedef enum _CellType
{
    BLANK = 0,
    WALL,//1
    BOX,//2
    BOXONTARGET,//3
    PERSON,//4
    PERSONONTARGET,//5
	TARGET//6
}CellType;

typedef struct _pbPoint
{
	int row;
	int col;
}PbPoint;

typedef struct _map
{
	PbPoint person;
	vector<PbPoint> boxes;
	vector<PbPoint> targets;
	int m_map[13][8];
	
}map;

class M8PushBoxLevelManager
{
public:
	M8PushBoxLevelManager(void);
	virtual ~M8PushBoxLevelManager(void);

void LoadLevel(	);
	map* GetLevel(int level);

	vector<map> m_maps;
	int m_totalLevelCnt;
};

#endif