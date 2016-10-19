#include "stdafx.h"
#include "BSPAlgorithm.h"
#include <vector>
#include "DungeonRect.h"
#include <sstream>

template<typename T>
unsigned int BSPTreeNode<T>::_ID = 0;

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

	DungeonRect *r = new DungeonRect(0, 0, width, height);
	BSPTreeNode<DungeonRect> *root = new BSPTreeNode<DungeonRect>(r, nullptr, nullptr, false, nullptr);
	std::vector<BSPTreeNode<DungeonRect> *> candidates;

	std::ostringstream out;
	out << "Starting from root: " << root->_data->debug() << std::endl;
	printf("%s", out.str().c_str());

	candidates.push_back(root);

	while (true)
	{
		if (candidates.size() <= 0)
			break;

		printf("======================== Next Turn ============================\n");
		BSPTreeNode<DungeonRect> *current = candidates[0];
		candidates.erase(candidates.begin());

		out.str("");
		out << "Current Node: " << current->_data->debug() << std::endl;
		printf("%s", out.str().c_str());

		int currentWidth = current->_data->getWidth();
		int currentHeight = current->_data->getHeight();
		int area = currentWidth * currentHeight;
		
		if (area < ROOM_MIN_SIZE * 2 || currentWidth < 6 || currentHeight < 6)
		{
			out.str("");
			out << "Area is too small, skip: " << area << std::endl;
			printf("%s", out.str().c_str());
			current->_isLeaf = true;
			continue;
		}
		else
		{
			out.str("");
			out << "Area is big enough to split: " << area << std::endl;
			printf("%s", out.str().c_str());

			// random direction
			int dir = rand() % 2;

			if (dir == 0)
			{
				// vertical
				int a = 3; int b = currentWidth - 3;
				int point = 3 + rand()%(b - a + 1);

				out.str("");
				out << "vertical split: " << point << std::endl;
				printf("%s", out.str().c_str());

				DungeonPoint lb = current->_data->getLeftBottom();
				DungeonRect *rl = new DungeonRect(lb.x, lb.y, point, currentHeight);
				DungeonRect *rr = new DungeonRect(lb.x + point, lb.y, currentWidth - point, currentHeight);
				
				out.str("");
				out << "Split into 2 parts: " << std::endl;
				out << "[1]" << rl->debug() << std::endl;
				out << "[2]" << rr->debug() << std::endl;
				printf("%s", out.str().c_str());

				BSPTreeNode<DungeonRect> *ln = new BSPTreeNode<DungeonRect>(rl, nullptr, nullptr, false, current);
				BSPTreeNode<DungeonRect> *rn = new BSPTreeNode<DungeonRect>(rr, nullptr, nullptr, false, current);
				
				current->_left = ln;
				current->_right = rn;

				candidates.push_back(ln);
				candidates.push_back(rn);
			}
			else
			{
				// horizontal
				int a = 3; int b = currentHeight - 3;
				int point = 3 + rand() % (b - a + 1);

				out.str("");
				out << "horizontal split: " << point << std::endl;
				printf("%s", out.str().c_str());

				DungeonPoint lb = current->_data->getLeftBottom();
				DungeonRect *ru = new DungeonRect(lb.x, lb.y + point, currentWidth, currentHeight - point);
				DungeonRect *rd = new DungeonRect(lb.x, lb.y, currentWidth, point);

				out.str("");
				out << "Split into 2 parts: " << std::endl;
				out << "[1]" << ru->debug() << std::endl;
				out << "[2]" << rd->debug() << std::endl;
				printf("%s", out.str().c_str());

				BSPTreeNode<DungeonRect> *un = new BSPTreeNode<DungeonRect>(ru, nullptr, nullptr, false, current);
				BSPTreeNode<DungeonRect> *dn = new BSPTreeNode<DungeonRect>(rd, nullptr, nullptr, false, current);

				current->_left = un;
				current->_right = dn;

				candidates.push_back(un);
				candidates.push_back(dn);
			}
		}
//		getchar();
	}

	clearAllNodes(root);
}
