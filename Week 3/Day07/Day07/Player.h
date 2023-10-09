#pragma once
#include <string>
#include "position.h"
class Player
{
public:
	void Move(int deltaX, int deltaY, int deltaZ);

	float Health() const { return health_; }
	void Health(float newHealth) { health_ = newHealth; }

	//write a ctor to initialize the position and gamer tag
	Player(std::string gamerTag, int wX, int wY, int wZ);
private:
	Position world;
	//int worldX_, worldY_, worldZ_;
	std::string gamerTag_;
	float health_, experience_, armorLevel_;

};

