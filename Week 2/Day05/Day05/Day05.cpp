// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include "Day05.h"

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

int Linear(const std::vector<int>& searchVector, int searchItem)
{
    int foundIndex = -1;
    for (size_t i = 0; i < searchVector.size(); i++)
    {
        if (searchItem == searchVector[i])
        {
            foundIndex = i;
            break;
        }
    }
    return foundIndex;
}


void PrintCourse(const std::map<std::string, double>& grades)
{
    std::cout << "\n\n   PG2 2310   \n";
    for (auto& [student, grade] : grades)
    {
        std::cout << std::setw(6) << grade << "  " << student << "\n";
    }
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE 1:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int index = Linear(numbers, searchNumber);
    if (index >= 0)
        std::cout << searchNumber << " was found at index " << index << "\n";
    else
        std::cout << searchNumber << " was NOT found.\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a Dictionaruy:
        1) using the insert method.
        3) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    //declare a map variable
    std::map<std::string, float> menu;

    auto pair = std::make_pair<std::string, float>("Cheese Burger", 20.0F);
    auto inserted2 = menu.insert(pair);//if already in the map, will NOT overwrite
    //OR...
    //map[key] = value;
    menu["Curly Fries"] = 8.49;
    menu["Curly Fries"] = 9.49;//overwrites the value
    menu["Chicken Salad"] = 15.49;
    menu["Pepperoni Pizza"] = 13.99;

    /*
        CHALLENGE 2:

            Create a map that stores names (string) and grades. 
            Call the variable grades.
            Add students and grades to your map.

    */
    std::vector<std::string> names{ "Noah W", "Sylas", "Nathan", "Chanaya", "Connor", "Dontai", "Jade", "James", "Noah A", "Phillip" };

    srand(time(NULL));
    std::map<std::string, double> grades;
    for (auto& student : names)
    {
        grades[student] = rand() % 101;
    }






    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }

    auto menuIter = menu.begin();
    while (menuIter != menu.end())
    {
        std::cout << menuIter->first << "\t" << menuIter->second << "\n";
        ++menuIter;
    }
    //OR...
    for (auto it = menu.begin(); it != menu.end(); ++it)
    {

    }

    std::cout << "\n\n  Missing CurlyBoy   \n";
    for (auto& [menuItem,price] : menu)
    {
        std::cout << menuItem << "\t" << price << "\n";
    }


    /*
        CHALLENGE 4:

            Loop over your grades map and print each student name and grade.

    */
    PrintCourse(grades);



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }

    auto menuFind = menu.find("Chicken Salad");
    if (menuFind != menu.end()) //found it!
        std::cout << menuFind->first << " costs " << menuFind->second << "\n";
    else
        std::cout << "That is not on the menu! Try McDonald's\n";



    /*
        CHALLENGE 5:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */
    std::string studentToFind = "Noah W";
    auto foundStudent = grades.find(studentToFind);
    if (foundStudent != grades.end())
        std::cout << studentToFind << " has a grade of " << foundStudent->second << "\n";
    else
        std::cout << studentToFind << " is not in PG2 this month.\n";

    std::cout << grades["Diana Prince"] << "\n";



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe


    std::string salad = "Chicken Salad";
    menu[salad] = 21.99;
    std::cout << salad << " now costs " << menu[salad] << "! Thanks Putin.\n";


    /*
        CHALLENGE 6:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
    std::string studentToCurve = "Sylas";
    char first = studentToCurve[0];
    std::cout << first << "\n";
    double& sylasGrade = grades[studentToCurve];//get the value
    sylasGrade = std::min<double>(100, sylasGrade + 5);
    //grades[studentToCurve] = std::min<double>(100, sylasGrade + 5);
    PrintCourse(grades);
}