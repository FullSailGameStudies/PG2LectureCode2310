// Day01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include "Calculator.h"

int AddOne(int localNumber)
{
    return localNumber + 1;
}

void print(const std::vector<std::string>& names)
{
    std::cout << "----NAMES----\n";
    int index = 1;
    for (std::string name : names)
        std::cout << index++ << ". " << name << "\n";
}


int main()
{
    /*
      Calling a method
        use the methods name.
        1) if the method needs data (i.e. has parameters), you must pass data to the method that matches the parameter types
        2) if the method returns data, it is usually best to store that data in a variable on the line where you call the method.

    */
    Calculator t800;
    //to talk to NON-static methods, use the variable
    int n1 = 5, n2 = 10;
    int result = t800.minus(n1, n2);//pass by value. making a COPY of these variables.
    //to talk to the STATIC method, use the CLASS NAME
    double factor = Calculator::mult(5, 3);

    /*
        ╔══════════════════════════╗
        ║Parameters: Pass by Value.║
        ╚══════════════════════════╝

        Copies the value to a new variable in the method.

        For example, the AddOne method has a parameter called localNumber. localNumber is a variable that is local ONLY to the method.
        The value of the variable in main, number, is COPIED to the variable in AddOne, localNumber.

    */
    int number = 5;
    int plusOne = AddOne(number);

    //Examples:
    //  calling a static method, prefix with the class name...
    factor = Calculator::mult(5, 3);

    //calling a non-static method, use the variable...
    Calculator t1000;
    int diff = t1000.minus(7, 2);


    /*
        CHALLENGE #1:

            Add an isEven method to the calculator.
            It should take 1 parameter and return a bool.

            Call the method on the t1000 calculator instance and print the results.

    */
    int challenge1 = 12;
    bool evenOrNot = t1000.isEven(challenge1);
    //ternary operator. (condition) ? true block : false block
    std::cout << "\nChallenge 1:\nIs this number even? " << challenge1 << " " << ((evenOrNot) ? "TRUE" : "FALSE") << "\n";



    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Creating a vector  ]

        vector<T>  - the T is a placeholder for a type.

        When you want to create a vector variable, replace T with whatever type of data you want to store in the vector.



        [  Adding items to a vector  ]

        There are 2 ways to add items to a vector:
        1) on the initializer.
        2) using the push_back(item) method.
    */
    std::vector<std::string> names { "Batman", "Bruce Wayne", "The Best" };
    names.push_back("The Greatest Detective");//add the BACK (end) of the vector
    names.push_back("The Bat");
    names.push_back("The Joker");
    names.push_back("Bane");
    names.push_back("Poison Ivy");


    /*
        CHALLENGE #2:

            Create a vector that stores floats. Call the variable grades.
            Add a few grades to the grades vector.

    */
    std::vector<float> grades;
    grades.push_back(rand() % 101);
    grades.push_back(rand() % 101);
    grades.push_back(rand() % 101);
    grades.push_back(rand() % 101);



    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Looping over a vector  ]

        You can loop over a vector with a for loop with iterators or a range-based for loop.

    */
    // begin() -- returns an iterator pointing to the first element
    // end() – returns an iterator pointing to the element AFTER the last element
    std::cout << "--- for loop:\n";
    for (int i = 0; i < names.size(); i++)
    {
        std::cout << names[i] << "\n";
    }
    std::cout << "\n\n";


    std::cout << "--- for loop with iterators:\n";
    for (auto i = names.begin(); i != names.end(); ++i)
    {
        std::cout << *i << std::endl;
    }
    std::cout << "\n\n";

    std::cout << "--- Range-based for loop:\n";
    for (std::string name : names)
        std::cout << name << std::endl;
    std::cout << "\n\n";

    /*
        CHALLENGE #3:

            loop over the grades vector and print out each grade

    */
    std::cout << "\n\n   PG2 Grades   \n";
    for (float& grade : grades)
    {
        std::cout << grade << "\n";
    }
    for (size_t i = 0; i < grades.size(); i++)
    {
        std::cout << grades[i] << "\n";
    }





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(names);

    //remove the joker. 6th item or 5 after the first item.
    names.erase(names.end()-1);

    std::cout << "\nerase the 5th item (" << names[4] << ")\n";
    names.erase(names.begin() + 4); //the position is the 4th item AFTER the first element. in other words, the 5th item.
    print(names);

    std::cout << "\nerase the 3rd item (" << names[2] << ") up to but not including the 5th item (" << names[4] << ")\n";
    std::vector<std::string>::iterator start = names.begin() + 2;//start at the 3rd item.
    std::vector<std::string>::iterator end = start + 2;//ends at the 5th item. 
    names.erase(start, end);//erases elements 3 and 4 but stops at the 5th.
    print(names);


    names.clear();
    std::cout << "\nclear all elements\n";
    print(names);



    /*

        CHALLENGE #4:

            Using the vector of grades you created.
            Remove the last item in the vector.
            Print the grades.

    */
    grades.erase(grades.end() - 1);





    /*
        BOSS CHALLENGE:

            1) Add an Average method to the calculator class to calculate the average of a vector.
            2) Call the Average method on the t1000 variable and pass your grades vector to the method.
            3) print the average that is returned.

    */
    float avg = t1000.Average(grades);
    std::cout << "Average grade in PG2 for October: " << avg << "!\n";

}
