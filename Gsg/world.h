#pragma once

#define PROVINCE_COUNT 100
#define COUNTRY_COUNT 5

#include <SFML\Graphics.hpp>

#include <string>
#include <iostream>
#include <vector>

#include "country.h"
#include "province.h"
#include "dbg_str.h"

class World : public sf::Drawable
{
public:
	World();
	~World();

	void init(int sw, int sh, sf::RenderWindow* wPtr);

	void handleStateChange(sf::Time dt);
	void handleKbdEvent(sf::Event evnt);
	void handleMouseEvent(sf::Vector2i pos, std::string button);
	void updateCursor(sf::RenderWindow* wnd);

	void changeMapMode(int mode);

	void receiveDateUpdate(float newDate);

	std::vector<std::string> getProvinceClicked();

	std::string getMapMode();

	sf::View mapView;
	sf::View hudView;

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void setProvinceClicked(sf::Vector2i mousePos);
	void setArmyDestination(sf::Vector2i mousePos);

	sf::RenderWindow* windowPtr;

	Province provinces[PROVINCE_COUNT];
	Country countries[COUNTRY_COUNT];

	

	DbgStr provinceMenu;
	DbgStr hudText[10];
	DbgStr selectedProvinceText[4];
	std::vector<std::string> provSelectedInfoStr = { 4, ("NULL", "NULL", "NULL", "NULL") };

	std::string mapmode;
	float date;

	int scrw;
	int scrh;

	bool debugMode;
	bool shown;

	sf::Sprite cursorSprite;
	sf::Texture cursorTex;

	sf::Sprite mapSprite;
	sf::Texture mapTex;

	sf::Image provinceColorMap;
};