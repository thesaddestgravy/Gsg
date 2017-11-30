#include "country.h"

void Country::init(std::string name, std::string armyLoc, int treasury)
{
	this->name = name;
	army.setLocation(armyLoc);
	this->treasury = treasury;
}