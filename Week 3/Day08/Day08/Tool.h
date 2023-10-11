#pragma once

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


private:

	//FIELDS: variables defined at the class level, not the method level
	Material material_;
	float durability_;
	float damage_;
};

