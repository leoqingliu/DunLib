#include "stdafx.h"
#include "DungeonActor.h"

extern bool SetConsoleColor(WORD wAttributes);

DunLib::DungeonActor::DungeonActor(int x, int y, ActorType t) : _x(x), _y(y), _type(t)
{
}

DunLib::DungeonActor::~DungeonActor()
{
}

void DunLib::DungeonActor::debug() const
{
#ifdef WIN32
	SetConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_RED);
	printf("P");
#endif // WIN32

}
