#include "stdafx.h"
#include "DungeonRect.h"
#include "Dungeon.h"
#include "DungeonMap.h"
#include "DungeonGenerationAlgorithm.h"
#include "BSPAlgorithm.h"

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

void DungeonMap::processData(void * d)
{
	if (!Dungeon::g_dungeon || !d)
		return;

	if (Dungeon::g_dungeon->_algorithm == DungeonAlgorithm::BSP)
	{
		BSPTreeNode<DungeonRect> *root = static_cast<BSPTreeNode<DungeonRect> *>(d);
		DungeonRect *r = root->_data;
		debugRoom(r);
		debug();
		printf("Press enter key to next...");
		getchar();
		BSPTreeNode<DungeonRect> *left = root->_left;
		BSPTreeNode<DungeonRect> *right = root->_right;

		if (left)
			processData(left);

		if (right)
			processData(right);
	}
}

void DungeonMap::debugRoom(DungeonRect * r)
{
	DungeonPoint lb = r->getLeftBottom();
	int width = r->getWidth();
	int height = r->getHeight();

	// bottom wall
	for (int x = lb.x; x < lb.x + width; x++)
	{
		setWall(x, lb.y);
	}

	// top wall
	for (int x = lb.x; x < lb.x + width; x++)
	{
		setWall(x, lb.y + height - 1);
	}

	// left wall
	for (int y = lb.y; y < lb.y + height; y++)
	{
		setWall(lb.x, y);
	}

	// right wall
	for (int y = lb.y; y < lb.y + height; y++)
	{
		setWall(lb.x + width - 1, y);
	}
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
	printf("#");
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
