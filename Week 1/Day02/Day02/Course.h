#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
class Course
{
private:

	std::vector<float> grades_;

	void GetGrades()
	{
		for (size_t i = 0; i < 10; i++)
		{
			grades_.push_back(rand() % 101);
		}
	}

public:
	Course()
	{
		GetGrades();
	}

	void Print(const std::string& title) const
	{
		std::cout << "\n---" << title << "---\n";
		for (auto& grade : grades_)
		{
			std::cout << std::setw(8) << grade << "\n";
		}
	}


	void GetStats(float& min, float& max) const
	{
		min = grades_[0];
		max = grades_[0];

		for (auto& grade : grades_)
		{
			if (min > grade) min = grade;
			max = std::max<float>(max, grade);
		}
	}
};

