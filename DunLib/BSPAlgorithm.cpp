#include "stdafx.h"
#include "BSPAlgorithm.h"
#include <vector>
#include "DungeonRect.h"
#include <sstream>

BSPAlgorithm::BSPAlgorithm()
{
}

BSPAlgorithm::~BSPAlgorithm()
{
}

void BSPAlgorithm::generateRooms(DungeonMap * map)
{
	if (map == nullptr)
		return;

	int width = map->getWidth();
	int height = map->getHeight();

	DungeonRect r(0, 0, width, height);
	BSPTreeNode<DungeonRect> root = {&r, nullptr, nullptr};
	std::vector<BSPTreeNode<DungeonRect>> candidates;

	std::ostringstream out;
	out << "Starting from root: " << root._data->debug() << std::endl;
	printf("%s", out.str().c_str());

	candidates.push_back(root);

	while (true)
	{
		if (candidates.size() <= 0)
			break;

		BSPTreeNode<DungeonRect> current = candidates[0];
		candidates.erase(candidates.begin());

		out.str("");
		out << "Current Node: " << current._data->debug() << std::endl;
		printf("%s", out.str().c_str());

		int area = current._data->getWidth() * current._data->getHeight();
		
		if (area < ROOM_MIN_SIZE * 2)
		{
			out.str("");
			out << "Area is too small, skip: " << area << std::endl;
			printf("%s", out.str().c_str());
			continue;
		}
		else
		{
			out.str("");
			out << "Area is big enough to split: " << area << std::endl;
			printf("%s", out.str().c_str());

			// random direction
			int dir = rand()%2;

			if (dir == 0)
			{
				// vertical
				out.str("");
				out << "vertical split " << std::endl;
				printf("%s", out.str().c_str());

				int point = rand()%(current._data->getWidth());
				DungeonPoint lb = current._data->getLeftBottom();
//				DungeonRect rl(, , , );
//				DungeonRect rr(, , , );


			}
			else
			{
				// horizontal
				out.str("");
				out << "horizontal split " << std::endl;
				printf("%s", out.str().c_str());

				int point = rand() % (current._data->getHeight());
				DungeonPoint lb = current._data->getLeftBottom();
			}
		}

		getchar();
	}
}
