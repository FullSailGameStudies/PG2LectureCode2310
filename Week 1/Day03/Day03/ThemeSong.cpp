#include "ThemeSong.h"
#include <iostream>

void ThemeSong::BatTheme(std::string name, int numberOfNas) const
{
	for (size_t i = 0; i < numberOfNas; i++)
	{
		std::cout << "na ";
	}
	std::cout << name << "\n\n";
}
