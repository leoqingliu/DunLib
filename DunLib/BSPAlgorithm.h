#pragma once
#include "DungeonGenerationAlgorithm.h"

class DungeonRect;

template<typename T>
struct BSPTreeNode
{
	T* _data;
	BSPTreeNode *_left;
	BSPTreeNode *_right;
};

class BSPAlgorithm :public DungeonGenerationAlgorithm
{
public:
	BSPAlgorithm();
	~BSPAlgorithm();

	void generateRooms(DungeonMap* _map);
};

