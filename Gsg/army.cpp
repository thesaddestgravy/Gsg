#include "army.h"

#include "province.h"

void Army::init(std::string location)
{
	this->location = location;
	isSelected = false;
}

void Army::setLocation(std::string provinceDesination)
{
	location = provinceDesination;
}

std::string Army::getLocation()
{
	return location;
}