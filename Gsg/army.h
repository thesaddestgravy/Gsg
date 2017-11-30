#pragma once

#include <string>


class Army
{
public:
	void init(std::string location);
	void setLocation(std::string provinceDesination);
	std::string getLocation();

	bool isSelected;
private:
	std::string location;
};