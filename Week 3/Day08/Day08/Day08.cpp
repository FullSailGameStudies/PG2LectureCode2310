﻿// Day08.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include "Inheritance.h"
#include "Polymorphism.h"
#include "Car.h"
#include "Shovel.h"


int main()
{
	//these are all STACK instances. objects are created on the stack.
	Shovel digger(Material::Diamond);
	Shovel digger2(Material::Diamond);
	Shovel crafted = digger + digger2;

	digger.DoDamage();//calling the Shovel::DoDamage method
	digger.Show();
	Tool tool(Material::Netherite);

	Tool t2 = digger2;//cast and create a new object

	//unique pointers are allocated (memory) on the HEAP.
	//the variable in the stack POINTS to the memory location in the HEAP.
	{
		Shovel* pShovel = new Shovel(Material::Wood);//created on the HEAP
		Shovel* pShovel2 = pShovel;//pointing to the same object

		std::cout << pShovel << "\n";
		pShovel->Show();
		delete pShovel; //clean up the HEAP memory
		//if I don't delete pShovel, I have a memory leak
		//pShovel->Show();//BOOM!
		pShovel = nullptr;
		if (pShovel != nullptr)
			pShovel->Show();
	}

	{
		std::unique_ptr<Tool> uPtrTool = std::make_unique<Shovel>(Material::Iron);
		uPtrTool->Show();//checks the vtable, sees that it has been overridden and calls the Shovel's Show method
	}//when it goes out of scope, uShovel is cleaned up (deleted)


	int num = 10;
	long bigNum = num;//implicit cast
	num = bigNum;//?? 8 bytes to 4 bytes?!
	float fNum = 5;
	num = (int)fNum;//explicit cast
	/*
        ╔═══════════════╗
        ║  Inheritance  ║
        ╚═══════════════╝

								╔═════════╗     ╔══════════╗
				         class  ║SomeClass║  :  ║OtherClass║
								╚═════════╝     ╚══════════╝
									 │                │
									 └──┐             └──┐
								   ┌────▼────┐      ┌────▼────┐
								   │ Derived │      │  Base   │
								   │  Class  │      │  Class  │
								   └─────────┘      └─────────┘

			Access modes:
				public inheritance:
				protected inheritance:
				private inheritance: (default if not specified)
	


				CONSTRUCTORS: the derived constructor must call a base constructor
				public SomeClass(.....) : baseClass(....)


			Lecture Code: add a FlyingCar class that derives from Car
             
    */



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

            add a new class, Pistol, that derives from Weapon.
            Pistol should have fields with getters/setters for rounds and magCapacity.
            Add a constructor that calls the base constructor
	
	*/






	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Method Overloading:
			- changing the number of parameters
			- changing the types of the parameters

		Lecture Code: Overload the refuel method in Car

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Add an OVERLOAD of the calcDamage method in the Weapon class.
			The overload should take an int parameter called modifier
			to increase the damage when calculating the damage.

	*/





	/*
        ╔═════════════════════════════╗
        ║  COMPILE-TIME Polymorphism  ║
        ╚═════════════════════════════╝

		Operator Overloading

		Lecture Code: overload the + operator in Account

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		overload the + in the Pistol class to add 2 pistols
			- it sets the magCapacity to the max of the 2 pistols
			- adds the # of rounds from both pistols. should not exceed the magCapacity.
	*/






	/*
        ╔════════════════════════╗
        ║  RUNTIME Polymorphism  ║
        ╚════════════════════════╝

		╔═════════════╗
		║ OVERRIDING  ║ - changing the behavior of a base method
		╚═════════════╝

		1) add 'virtual' to the base method
		2) add a method to the derived class that has the same signature as the base.
			OPTIONALLY put 'override' on the derived method


		FULLY OVERRIDING:
			not calling the base method from the derived method

		EXTENDING:
			calling the base method from the derived method
			to call the base method...  baseClassName::method(...)



		Lecture Code: override the print method in the base/derived classes in the Polymorphism.h file

	*/



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

			Override Weapon's showMe method in the Pistol class.
			In Pistol's version, call the base version then print out the rounds and magCapacity



	*/




	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


        ╔═══════════╗ 
        ║ UPCASTING ║ - casting a derived type variable to a base type variable
        ╚═══════════╝ 

        This is ALWAYS safe.

	
		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);

		
		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code: 
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
        ╔*************╗
        ║  CHALLENGE  ║
        ╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/
}

