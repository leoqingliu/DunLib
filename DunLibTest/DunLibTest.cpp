// DunLibTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../DunLib/Dungeon.h"

using namespace DunLib;

int main()
{
	Dungeon d(DungeonAlgorithm::BSP);
	d.generate(80,45);

	getchar();
    return 0;
}

