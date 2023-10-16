#include "Hero.h"
#include <sstream>

Hero::Hero(std::string name, std::string secret, int age) :
	name_(name), secret_(secret), age_(age)
{
}

Hero::Hero(std::string csvData, char delimiter) :
	name_(""), secret_(""), age_(0)
{
	Deserialize(csvData, delimiter);
}

void Hero::Deserialize(std::string csvData, char delimiter)
{
	std::stringstream heroStream(csvData);
	std::getline(heroStream, name_, delimiter);
	std::getline(heroStream, secret_, delimiter);

	std::string ageData;
	std::getline(heroStream, ageData, delimiter);
	age_ = std::stoi(ageData);
}
