#pragma once
#include "Tool.h"
class Shovel : public Tool
{
public:
	//our derived ctor needs to call a base ctor
	//all the parts (shovel AND tool) need to be initialized
	Shovel(Material material) :
		Tool(material)
	{
		//TODO: modify the durability + damage based on being a shovel
	}
};

