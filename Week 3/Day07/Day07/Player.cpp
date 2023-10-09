#include "Player.h"

void Player::Move(int deltaX, int deltaY, int deltaZ)
{
	world.x += deltaX;
	world.y += deltaY;
	world.z += deltaZ;
}

Player::Player(std::string gamerTag, int wX, int wY, int wZ) :
	gamerTag_(gamerTag),
	world(wX,wY,wZ),
	experience_(0),
	armorLevel_(0),
	health_(13)
{
}
