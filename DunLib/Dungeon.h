#pragma once
#include "DungeonMap.h"
#include "DungeonActor.h"

enum DungeonAlgorithm
{
	EASY,
	BSP,
};

class Dungeon
{
public:
	Dungeon(DungeonAlgorithm algo);
	~Dungeon();
	static Dungeon *g_dungeon;
	void generate(int x, int y);
	DungeonAlgorithm _algorithm;

protected:
	
	DungeonMap *_map;

};
