#include "Pickaxe.h"
#include <algorithm>

Pickaxe::Pickaxe(Material material, float durability) :
	material_(material),
	durability_(durability) //member initialization list
{
}

void Pickaxe::MineSomething()
{
	ChangeDurability(-5);
}

void Pickaxe::ChangeDurability(float deltaChange)
{
	float newDurability = durability_ + deltaChange;
	durability_ = std::min<float>(std::max<float>(0, newDurability), 100);
}
