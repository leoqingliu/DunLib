#pragma once
#include "DungeonMap.h"

class DungeonGenerationAlgorithm
{
public:
	DungeonGenerationAlgorithm() {};
	virtual ~DungeonGenerationAlgorithm() {};
	virtual void generateRooms(DungeonMap *map) = 0;
};
