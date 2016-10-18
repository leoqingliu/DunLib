#include "stdafx.h"
#include "DungeonRect.h"


DunLib::DungeonRect::DungeonRect(int x, int y, int w, int h)
{
	_width = w;
	_height = h;

	_leftBottom.x = x;
	_leftBottom.y = y;

	_leftTop.x = x;
	_leftTop.y = y + h;

	_rightBottom.x = x + w;
	_rightBottom.y = y;

	_rightTop.x = x + w;
	_rightTop.y = y + h;
}

DunLib::DungeonRect::~DungeonRect()
{
}

DungeonPoint DunLib::DungeonRect::getCenter()
{
	int x = (_leftTop.x + _rightTop.x) >> 1;
	int y = (_leftTop.y + _leftBottom.y) >> 1;
	DungeonPoint p{x, y};
	return p;
}
