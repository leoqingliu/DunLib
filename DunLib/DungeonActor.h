#pragma once
namespace DunLib
{
	enum ActorType
	{
		PLAYER,
		NPC,
		MONSTER_1,
	};

	class DungeonActor
	{
	public:
		DungeonActor(int x, int y, ActorType t);
		~DungeonActor();

	public:
		int _x, _y; // position on map
		ActorType _type;
		void debug() const;
	};
}