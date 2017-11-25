#pragma once

#include <SFML\Graphics.hpp>
#include <string>

class Province : public sf::Drawable
{
public:
	Province();
	~Province();

	void create(const std::string& filename, const std::string& provOwner, sf::Vector2f node, sf::Vector2f base, sf::Color identifier, const std::string& rawResource, const std::string& rel);
	void setMapMode(int newMode);
	void updateSelected();

	bool isSelected;
	sf::Color oldColor;

	sf::Color getColID();
	std::string getID();
	std::string getOwner();
	std::string getResource();
	std::string getReligion();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;



	std::string ID;
	std::string owner;
	std::string resource;
	std::string religion;

	sf::RectangleShape armyZone;

	sf::Color IDCol;
	sf::Sprite img;
	sf::Texture tex;
};
