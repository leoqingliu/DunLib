#pragma once
namespace DunLib
{
	class DungeonRect
	{
	public:
		DungeonRect(int x, int y, int w, int h);
		~DungeonRect();

		inline int getWidth() const
		{
			return _width;
		}

		inline int getHeight() const
		{
			return _height;
		}

		DungeonPoint getCenter();

	protected:
		DungeonPoint _leftTop;
		DungeonPoint _leftBottom;
		DungeonPoint _rightTop;
		DungeonPoint _rightBottom;
		int _width;
		int _height;
	};

	typedef DungeonRect DungeonRoom;
}