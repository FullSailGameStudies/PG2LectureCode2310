#pragma once

#include <iostream>


void demo()
{
	static int count = 0; //created once
	std::cout << count << " ";
	count++;
}

class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	//static methods CANNOT access non-static fields/methods
	static void reporting()//do NOT have a 'this'
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	//non-static methods CAN access static fields/methods
	void vehicleInfo() //there's a hidden parameter called 'this'
	{
		std::cout << "Model Year: " << this->mModelYear << "\n";
	}

	static Car CarMaker(int year)
	{
		return Car(year);
	}
};

//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0; 

