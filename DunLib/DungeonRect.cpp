#include "stdafx.h"
#include "DungeonRect.h"


DungeonRect::DungeonRect(int x, int y, int w, int h)
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

DungeonRect::~DungeonRect()
{
}

DungeonPoint DungeonRect::getCenter()
{
	int x = (_leftTop.x + _rightTop.x) >> 1;
	int y = (_leftTop.y + _leftBottom.y) >> 1;
	DungeonPoint p{x, y};
	return p;
}

DungeonPoint DungeonRect::getLeftBottom()
{
	return _leftBottom;
}

std::string DungeonRect::debug()
{
	char buff[100];
	sprintf_s(buff, "[x = %d, y = %d, w = %d, h = %d]", _leftBottom.x, _leftBottom.y, _width, _height);
	return std::string(buff);
}
