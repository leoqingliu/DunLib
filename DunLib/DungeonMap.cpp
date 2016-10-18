#include "stdafx.h"
#include "DungeonMap.h"
#include "DungeonGenerationAlgorithm.h"

extern bool SetConsoleColor(WORD wAttributes);

DungeonMap::DungeonMap(int w, int h, DungeonGenerationAlgorithm* a) : _width(w), _height(h)
{
	_tiles = new DungeonTile[w * h];
	_algo = a;
	performAlgorithm();
}

DungeonMap::~DungeonMap()
{
	delete[] _tiles;
}

bool DungeonMap::isWall(int x, int y) const
{
	return !_tiles[x + y*_width].canWalk();
}

void DungeonMap::setWall(int x, int y)
{
	_tiles[x + y*_width].setWalk(false);
}

DungeonTile * DungeonMap::getTiles() const
{
	return _tiles;
}

void DungeonMap::setAlgorithm(DungeonGenerationAlgorithm* alg)
{
	_algo = alg;
}

int DungeonMap::getWidth() const
{
	return _width;
}

int DungeonMap::getHeight() const
{
	return _height;
}

void DungeonMap::debug()
{
#ifdef WIN32
	for (int y = 0; y < _height; y++) 
	{
		for (int x = 0; x < _width; x++)
		{
			bool wall = isWall(x, y);

			if (wall)
			{
				drawWall();
			}
			else
			{
				drawGround();
			}
		}
		printf("\n");
	}

#endif // WIN32
}

void DungeonMap::performAlgorithm()
{
	_algo->generateRooms(this);
}

void DungeonMap::dig(int startX, int startY, int endX, int endY)
{
	if (endX < startX) 
	{
		int tmp = endX;
		endX = startX;
		startX = tmp;
	}

	if (endY < startY)
	{
		int tmp = endY;
		endY = startY;
		startY = tmp;
	}

	for (int tilex = startX; tilex <= endX; tilex++)
	{
		for (int tiley = startY; tiley <= endY; tiley++) 
		{
			_tiles[tilex + tiley*_width].setWalk(true);
		}
	}
}

void DungeonMap::createRoom(bool first, int startX, int startY, int endX, int endY)
{
	dig(startX, startY, endX, endY);

	if (first)
	{
		// add hero here
	}
	else
	{
		// add NPC or monsters here
	}
}

#ifdef WIN32
void DungeonMap::drawWall()
{
	SetConsoleColor(FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	printf("W");
}

void DungeonMap::drawGround()
{
	printf(" ");
}
#endif // WIN32

//==================================================================================

DungeonTile::DungeonTile() : _canWalk(true)
{
}

bool DungeonTile::canWalk() const
{
	return _canWalk;
}

void DungeonTile::setWalk(bool b)
{
	_canWalk = b;
}
