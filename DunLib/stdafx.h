// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头中排除极少使用的资料



// TODO:  在此处引用程序需要的其他头文件
#include <utility>
typedef struct
{
	int x;
	int y;
}DungeonPoint;

#ifdef WIN32
#include <Windows.h>
#endif

#ifdef WIN32
bool SetConsoleColor(WORD wAttributes);

#endif // WIN32

static const int ROOM_MAX_SIZE = 24;
static const int ROOM_MIN_SIZE = 12;

