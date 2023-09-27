#include "Calculator.h"

int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

double Calculator::mult(double num, double factor)
{
	return num * factor;
}

bool Calculator::isEven(int number)
{
	return number % 2 == 0;
}

float Calculator::Average(std::vector<float> numbers)
{
	float avg = 0;
	for (float& number : numbers)
	{
		avg += number;
	}

	//for (size_t i = 0; i < numbers.size(); i++)
	//{
	//	avg += numbers[i];
	//}

	//for (auto i = numbers.begin(); i != numbers.end(); i++)
	//{
	//	avg += *i;
	//}
	return avg / numbers.size();
}
