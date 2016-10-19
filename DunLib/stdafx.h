// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�
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

