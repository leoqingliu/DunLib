#pragma once
#include "DungeonGenerationAlgorithm.h"

class DungeonRect;

template<typename T>
struct BSPTreeNode
{
	T* _data;
	BSPTreeNode *_left;
	BSPTreeNode *_right;
	bool _isLeaf;
	BSPTreeNode *_parent;
	unsigned int _iid;
	static unsigned int _ID;
	BSPTreeNode(T*, BSPTreeNode*, BSPTreeNode*, bool, BSPTreeNode*);
	virtual ~BSPTreeNode();
};

class BSPAlgorithm : public DungeonGenerationAlgorithm
{
public:
	BSPAlgorithm();
	~BSPAlgorithm();

	void generateRooms(DungeonMap* _map);
	
protected:
	template<typename T>
	void clearAllNodes(BSPTreeNode<T> *root);
};

template<typename T>
inline void BSPAlgorithm::clearAllNodes(BSPTreeNode<T> *r)
{
	if (!r)
		return;

	BSPTreeNode<T> *root = static_cast<BSPTreeNode<T> *>(r);

	auto left = root->_left;
	auto right = root->_right;

	if (left != nullptr)
	{
		clearAllNodes(left);
	}

	if (right != nullptr)
	{
		clearAllNodes(right);
	}

	delete root;
	root = nullptr;
}

template<typename T>
inline BSPTreeNode<T>::BSPTreeNode(T *d, BSPTreeNode *l, BSPTreeNode *r, bool b, BSPTreeNode *p) :
	_data(d), _left(l), _right(r), _isLeaf(b), _parent(p)
{
	_iid = _ID;
	printf("BSPTreeNode<T> ID = %d created.\n", _iid);
	_ID++;
}

template<typename T>
inline BSPTreeNode<T>::~BSPTreeNode()
{
	if (_data)
	{
		delete _data;
		_data = nullptr;
	}

	printf("BSPTreeNode<T> ID = %d deleted.\n", _iid);
}
