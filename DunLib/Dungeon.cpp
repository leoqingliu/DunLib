#include "stdafx.h"
#include "Dungeon.h"
#include "BSPAlgorithm.h"

Dungeon *Dungeon::g_dungeon = nullptr;

Dungeon::Dungeon(DungeonAlgorithm algo) : _map(nullptr)
{
	_algorithm = algo;
	g_dungeon = this;
}

Dungeon::~Dungeon()
{
	if (_map)
	{
		delete _map;
		_map = nullptr;
	}

	g_dungeon = nullptr;
}

void Dungeon::generate(int x, int y)
{
	DungeonGenerationAlgorithm *alg = nullptr;

	if (_algorithm == DungeonAlgorithm::BSP)
	{
		alg = new BSPAlgorithm;
		_map = new DungeonMap(x, y, alg);
	}
		
	delete alg;
	_map->debug();
}
