// Day02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Course.h"


void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

bool postFix(std::string& name)
{
    int num = rand();
    name = name + "-" + std::to_string(num);
    return num % 2 == 0;
}

void FillGrades(std::vector<float>& pg2)
{
    for (size_t i = 0; i < 10; i++)
    {
        pg2.push_back(rand() % 101);
    }
}

void PrintGrades(const std::vector<float>& grades)
{
    std::cout << "\n---PG2 2310---\n";
    for (auto& grade : grades)
    {
        std::cout << std::setw(8) << grade << "\n";
    }
}

void GetStats(const std::vector<float>& grades, float& min, float& max)
{
    min = grades[0];
    max = grades[0];

    for (auto& grade : grades)
    {
        if (min > grade) min = grade;
        max = std::max<float>(max, grade);
    }
}

int main()
{
    srand(time(NULL));
    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    std::vector<float> grades;
    FillGrades(grades);


    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    Course pg2;
    std::string myCourse = "PG2 2310";
    pg2.Print(myCourse);

    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
        highScores.push_back(rand());
    float avg = 0;// average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. 
                 Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */
    float minGrade, maxGrade;
    PrintGrades(grades);
    GetStats(grades, minGrade, maxGrade);
    std::cout << "Min Grade: " << minGrade << "\tMax grade: " << maxGrade << "\n";





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    //print(highScores);

    for (size_t i = 0; i < highScores.size();)
    {
        if (highScores[i] < 2500)
            highScores.erase(highScores.begin() + i);
        else
            ++i;
    }


    /*
        INTERMEDIATE LEVEL...
        a way using std::remove_if and a lambda
    highScores.erase(
        std::remove_if(highScores.begin(),
            highScores.end(),
            [](int score) { return score < 2500; }),
        highScores.end());
    */


    //print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}