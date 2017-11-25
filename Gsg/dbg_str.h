#pragma once

#include <SFML\Graphics.hpp>

class DbgStr : public sf::Drawable
{
public:
	DbgStr();
	~DbgStr();

	DbgStr(const std::string& text, const std::string& font, int size, sf::Vector2f pos);

	void create(const std::string& text, const std::string& font, int size, sf::Vector2f pos);
	void set(std::string newStr);
	void setPos(sf::Vector2f newPos);

	std::string getString();
	sf::FloatRect getBounds();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Text words;
	sf::Font font;

	sf::FloatRect boundingRect;

};

