#include "dbg_str.h"



DbgStr::DbgStr()
{

}

DbgStr::DbgStr(const std::string& text, const std::string & font, int size, sf::Vector2f pos)
{
	words.setString(text);
	DbgStr::font.loadFromFile("res/" + font + ".ttf");
	words.setFont(DbgStr::font);
	words.setCharacterSize(size);
	words.setPosition(pos);
}
void DbgStr::create(const std::string& text, const std::string& font, int size, sf::Vector2f pos)
{
	words.setOutlineThickness(3);
	words.setString(text);
	DbgStr::font.loadFromFile("res/" + font + ".ttf");
	words.setFont(DbgStr::font);
	words.setCharacterSize(size);
	words.setPosition(pos);
}

void DbgStr::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(words);
}

void DbgStr::set(std::string newStr)
{
	words.setString(newStr);
}

void DbgStr::setPos(sf::Vector2f newPos)
{
	words.setPosition(newPos);
}

std::string DbgStr::getString()
{
	return words.getString();
}

sf::FloatRect DbgStr::getBounds()
{
	return words.getGlobalBounds();
}

DbgStr::~DbgStr()
{

}
