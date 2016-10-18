#pragma once

class DungeonGenerationAlgorithm;


	class DungeonTile;

	class DungeonMap
	{
	public:
		DungeonMap(int w, int h, DungeonGenerationAlgorithm* a);
		~DungeonMap();

		bool isWall(int x, int y) const;
		void setWall(int x, int y);
		DungeonTile* getTiles() const;
		void setAlgorithm(DungeonGenerationAlgorithm *alg);

		void debug();
		DungeonMap(DungeonMap &) = delete;

	protected:
		int _width;
		int _height;
		DungeonTile *_tiles;
		DungeonGenerationAlgorithm *_algo;

		void performAlgorithm();

		// 挖一个房间
		void dig(int startX, int startY, int endX, int endY);

		// 创建一个房间
		void createRoom(bool first, int startX, int startY, int endX, int endY);

#ifdef WIN32
		void drawWall();
		void drawGround();
#endif // WIN32
		
	};

	class DungeonTile
	{
	public:
		DungeonTile();
		bool canWalk() const;
		void setWalk(bool b);
	protected:
		bool _canWalk;
	};



