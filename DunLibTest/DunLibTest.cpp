// DunLibTest.cpp : �������̨Ӧ�ó������ڵ㡣
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

