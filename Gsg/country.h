#pragma once

#include <SFML\Graphics.hpp>

#include <string>

#include "army.h"

class Country
{
public:
	void init(std::string name, std::string armyLoc, int treasury);
	std::string name;

	Army army;

private:
	int treasury;

};