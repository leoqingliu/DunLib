#pragma once
#include "DungeonGenerationAlgorithm.h"

class BSPAlgorithm :public DungeonGenerationAlgorithm
{
public:
	BSPAlgorithm();
	~BSPAlgorithm();

	void generateRooms(DungeonMap* _map);
};

