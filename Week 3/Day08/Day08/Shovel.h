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
		damage_ += 1;
	}

	float DoDamage() override
	{
		//do something different than the base
		float baseDamage = Tool::DoDamage();//EXTENDING the base when you call the base version

		//IF you don't call the base version, you are FULLY OVERRIDDING the base
		return baseDamage + 0.5F;
	}

	void Show() override
	{
		std::cout << "\nI am a " << GetMaterial() << " shovel that does " << damage_ << " damage.\n";
	}

	Shovel operator+(Shovel const& otherShovel)
	{
		if (material_ == otherShovel.material_)
		{
			Shovel s3(material_);
			//TODO: combine the durability + 5%
			return s3;
		}
		return *this;
	}
};

