#include "utils.h"

CMzString GetMyPath()
{
    HMODULE hmodule;
    hmodule = GetModuleHandleW(NULL);
    WCHAR path[MAX_PATH];
    int i = GetModuleFileNameW(hmodule, path, MAX_PATH);

    for (; i >= 0 ; i--)
    {
        if (path[i] == L'\\')
        {
            path[i] = 0;
            break;
        }
    }
    return CMzString(path);
}
CMzString GetFullPath(CMzString file)
{
	CMzString str;
	str=GetMyPath();
	return str+file;
}