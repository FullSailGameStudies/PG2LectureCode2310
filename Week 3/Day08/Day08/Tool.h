#pragma once
#include <iostream>
#include <string>

enum Material
{
	Wood, Stone, Iron, Diamond, Netherite
};


class Tool //base for all the other tools
{
public:
	//Tool() : material_(Wood), durability_(10.0F), damage_(1.0F)
	//{

	//}
	Tool(Material material) : material_(material), durability_(10.0F), damage_(1.0F)
	{
		//TODO: do some work to initialize the durability and damage based on the material
	}
	Tool(Material material, float durability, float damage) : 
		material_(material), durability_(durability), damage_(damage)
	{}

	//tells the compiler that the method MIGHT be overridden in a derived class
	virtual float DoDamage()
	{
		//take the damage and return some random effect
		return 0.0F;
	}

	//getters (accessors)
	Material GetMaterial() const
	{
		return material_;
	}

	float Durability() const
	{
		return durability_;
	}

	float Damage() const
	{
		return damage_;
	}

	//setters (mutators)
	void SetMaterial(Material material)
	{
		material_ = material; //always set the field = parameter
	}

	void Durability(float durability)
	{
		durability_ = durability;
	}

	void Damage(float damage)
	{
		damage_ = damage;
	}


	//override this method in the Shovel class
	virtual void Show()
	{
		std::cout << "\nI am a " << GetMaterial() << " tool that does " << damage_ << " damage.\n";
	}


protected:
	std::string GetMaterial()
	{
		std::string material = "unknown";
		switch (material_)
		{
		case Wood:
			material = "Wood";
			break;
		case Stone:
			material = "Stone";
			break;
		case Iron:
			material = "Iron";
			break;
		case Diamond:
			material = "Diamond";
			break;
		case Netherite:
			material = "Netherite";
			break;
		default:
			break;
		}
		return material;
	}

	//FIELDS: variables defined at the class level, not the method level
	Material material_;
	float durability_;
	float damage_;
};

