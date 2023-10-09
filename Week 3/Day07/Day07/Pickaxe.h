#pragma once
#include "enums.h"

class Pickaxe
{
public:
	//the compiler provides a DEFAULT constructor IFF we have not provided ANY ctor
	Pickaxe(Material material, float durability);

	void MineSomething();//declare what the class can do

	//getters (accessors)
	Material GetMaterial() const
	{
		return material_;
	}

	float Durability() const
	{
		return durability_;
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


protected:

private:

	//FIELDS: variables defined at the class level, not the method level
	Material material_;
	float durability_;

	void ChangeDurability(float deltaChange);
};

