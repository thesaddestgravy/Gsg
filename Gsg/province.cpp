#include "province.h"



Province::Province()
{

}

void Province::create(const std::string& filename, const std::string& provOwner, sf::Vector2f node, sf::Vector2f base, sf::Color identifier, const std::string& rawResource, const std::string& rel)
{
	tex.loadFromFile("res/provinces/" + filename + ".png");

	img.setTexture(tex);

	img.setPosition(node + base);

	armyZone.setSize(sf::Vector2f(20, 20));
	armyZone.setPosition((img.getPosition().x + img.getTextureRect().width / 2.0 - armyZone.getSize().x / 2), (img.getPosition().y + img.getTextureRect().height / 2.0 - armyZone.getSize().y / 2));
	armyZone.setFillColor(sf::Color::Red);

	isSelected = false;

	ID = filename;
	owner = provOwner;
	resource = rawResource;
	IDCol = identifier;
	religion = rel;
}

void Province::setMapMode(int newMode)
{

	if (newMode == 1)
	{
		if (owner == "France")
		{
			img.setColor(sf::Color(77, 80, 165));
		}

		if (owner == "Spain")
		{
			img.setColor(sf::Color(224, 214, 105));
		}
	}

	if (newMode == 2)
	{
		if (resource == "grain")
		{
			img.setColor(sf::Color(150, 200, 85));
		}

		if (resource == "wine")
		{
			img.setColor(sf::Color(153, 78, 135));
		}

		if (resource == "weaponry")
		{
			img.setColor(sf::Color(255, 230, 60));
		}

		if (resource == "wood")
		{
			img.setColor(sf::Color(153, 106, 50));
		}

		if (resource == "textiles")
		{
			img.setColor(sf::Color(173, 58, 99));
		}


		if (resource == "metals")
		{
			img.setColor(sf::Color(128, 128, 128));
		}

	}

	oldColor = img.getColor();

}

void Province::updateSelected()
{

	if (isSelected)
	{
		img.setColor(sf::Color(50, 50, 50));
	}
	else
	{
		img.setColor(oldColor);
	}
}

sf::Color Province::getColID()
{
	return IDCol;
}

std::string Province::getID()
{
	return ID;
}

std::string Province::getOwner()
{
	return owner;
}

std::string Province::getResource()
{
	return resource;
}

std::string Province::getReligion()
{
	return religion;
}

void Province::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(img);
	target.draw(armyZone);
}

Province::~Province()
{

}
