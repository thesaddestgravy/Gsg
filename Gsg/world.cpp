#define DEBUG_TOGGLE 0
#define VERSION_HEADER 1
#define CURRENT_MAPMODE 2
#define MAPMODE_DATA 3
#define PROVINCE_SELECTED_NAME 4
#define DATE 5
#define GAME_STATE 6

#include "world.h"

World::World()
{

}

void World::init(int sw, int sh, sf::RenderWindow* wPtr)
{
	std::cout << "initializing world...\n";

	scrw = sw;
	scrh = sh;

	windowPtr = wPtr;

	shown = true;
	debugMode = true;

	std::cout << "\tinitializing HUD...";

	cursorTex.loadFromFile("res/cursor.png");
	cursorSprite.setTexture(cursorTex);

	hudView.setSize(sf::Vector2f(scrw, scrh));
	hudView.setCenter(sf::Vector2f(scrw / 2.0, scrh / 2.0));

	hudText[DEBUG_TOGGLE].create("Debug mode: on", "basis33", 32, sf::Vector2f(0, scrh - 15 - 25));
	hudText[VERSION_HEADER].create("Frost v0.1.1-alpha build 17.11.30", "basis33", 26, sf::Vector2f(2, -9));
	hudText[CURRENT_MAPMODE].create("Current mapmode: political", "basis33", 32, sf::Vector2f(scrw - 440, scrh - 42));
	hudText[MAPMODE_DATA].create("NULL", "basis33", 32, sf::Vector2f(scrw - 440, scrh - 65));
	hudText[PROVINCE_SELECTED_NAME].create("Province name: ", "basis33", 32, sf::Vector2f(scrw - 440, scrh - 87));
	hudText[DATE].create("Day: ", "basis33", 32, sf::Vector2f(scrw - 400, -12));

	selectedProvinceText[0].create("", "basis33", 32, sf::Vector2f(0, scrh - 15 - 55));
	selectedProvinceText[1].create("", "basis33", 32, sf::Vector2f(0, scrh - 15 - 85));
	selectedProvinceText[2].create("", "basis33", 32, sf::Vector2f(0, scrh - 15 - 95));
	selectedProvinceText[3].create("", "basis33", 32, sf::Vector2f(0, scrh - 15 - 115));

	std::cout << "done.\n";



	std::cout << "\tinitializing map...";

	mapView.setSize(sf::Vector2f(scrw, scrh));
	


	mapTex.loadFromFile("res/mapeurope.png");

	mapView.setCenter(sf::Vector2f(mapTex.getSize().x / 2.0, mapTex.getSize().y / 2.0));

	mapSprite.setTexture(mapTex);

	provinceColorMap.loadFromFile("res/colormap.png");

	//this is the popup that displays on the mouse click position when a province is clicked. will be replaced with full menu soon™
	provinceMenu.create("", "basis33", 32, sf::Vector2f(0, 0));

	//french starting provinces
	provinces[0].create("calais", "France", sf::Vector2f(1425, 3263), mapSprite.getPosition(), sf::Color(81, 110, 255), "grain", "catholic");
	provinces[1].create("picardie", "France", sf::Vector2f(1395, 3345), mapSprite.getPosition(), sf::Color(71, 163, 255), "grain", "catholic");
	provinces[2].create("normandie", "France", sf::Vector2f(1164, 3384), mapSprite.getPosition(), sf::Color(239, 124, 255), "grain", "catholic");
	provinces[3].create("paris", "France", sf::Vector2f(1380, 3458), mapSprite.getPosition(), sf::Color(255, 66, 56), "textiles", "catholic");
	provinces[4].create("alencon", "France", sf::Vector2f(1223, 3510), mapSprite.getPosition(), sf::Color(73, 170, 255), "grain", "catholic");
	provinces[5].create("bretagne", "France", sf::Vector2f(960, 3510), mapSprite.getPosition(), sf::Color(30, 53, 255), "wood", "catholic");
	provinces[6].create("anjou", "France", sf::Vector2f(1185, 3570), mapSprite.getPosition(), sf::Color(114, 255, 154), "textiles", "catholic");
	provinces[7].create("champagne", "France", sf::Vector2f(1508, 3375), mapSprite.getPosition(), sf::Color(89, 255, 141), "wine", "catholic");
	provinces[8].create("nemours", "France", sf::Vector2f(1455, 3533), mapSprite.getPosition(), sf::Color(255, 50, 35), "grain", "catholic");
	provinces[9].create("orleanais", "France", sf::Vector2f(1328, 3548), mapSprite.getPosition(), sf::Color(255, 223, 45), "metals", "catholic");
	provinces[10].create("bourgogne", "France", sf::Vector2f(1485, 3540), mapSprite.getPosition(), sf::Color(246, 76, 255), "grain", "catholic");
	provinces[11].create("poitou", "France", sf::Vector2f(1163, 3698), mapSprite.getPosition(), sf::Color(38, 189, 255), "grain", "catholic");
	provinces[12].create("limousin", "France", sf::Vector2f(1350, 3728), mapSprite.getPosition(), sf::Color(151, 255, 122), "grain", "catholic");
	provinces[13].create("bordeaux", "France", sf::Vector2f(1215, 3840), mapSprite.getPosition(), sf::Color(109, 221, 255), "grain", "catholic");
	provinces[14].create("auvergne", "France", sf::Vector2f(1485, 3743), mapSprite.getPosition(), sf::Color(255, 182, 160), "metals", "catholic");
	provinces[15].create("lyon", "France", sf::Vector2f(1628, 3758), mapSprite.getPosition(), sf::Color(151, 255, 91), "grain", "catholic");
	provinces[16].create("languedoc", "France", sf::Vector2f(1598, 3893), mapSprite.getPosition(), sf::Color(255, 224, 25), "grain", "catholic");
	provinces[17].create("dauphine", "France", sf::Vector2f(1725, 3773), mapSprite.getPosition(), sf::Color(255, 33, 25), "grain", "catholic");
	provinces[18].create("provence", "France", sf::Vector2f(1680, 4020), mapSprite.getPosition(), sf::Color(91, 91, 255), "wine", "catholic");
	provinces[19].create("labourd", "France", sf::Vector2f(1178, 4020), mapSprite.getPosition(), sf::Color(56, 255, 215), "grain", "catholic");
	provinces[20].create("toulouse", "France", sf::Vector2f(1395, 3960), mapSprite.getPosition(), sf::Color(255, 58, 143), "grain", "catholic");
	provinces[21].create("gascony", "France", sf::Vector2f(1290, 3975), mapSprite.getPosition(), sf::Color(255, 231, 124), "grain", "catholic");
	provinces[22].create("guyenne", "France", sf::Vector2f(1305, 3825), mapSprite.getPosition(), sf::Color(120, 71, 255), "grain", "catholic");

	//spanish starting provinces
	provinces[23].create("catalonia", "Spain", sf::Vector2f(1329, 4140), mapSprite.getPosition(), sf::Color(48, 255, 162), "alcohol", "catholic");
	provinces[24].create("valencia", "Spain", sf::Vector2f(1215, 4329), mapSprite.getPosition(), sf::Color(255, 140, 0), "textiles", "catholic");
	provinces[25].create("aragon", "Spain", sf::Vector2f(1155, 4110), mapSprite.getPosition(), sf::Color(255, 91, 66), "metals", "catholic");
	provinces[26].create("navarra", "Spain", sf::Vector2f(1065, 4089), mapSprite.getPosition(), sf::Color(255, 243, 84), "metals", "catholic");
	provinces[27].create("castillaleon", "Spain", sf::Vector2f(780, 4095), mapSprite.getPosition(), sf::Color(71, 255, 224), "grain", "catholic");
	provinces[28].create("cantabria", "Spain", sf::Vector2f(939, 4080), mapSprite.getPosition(), sf::Color(89, 255, 152), "weaponry", "catholic");
	provinces[29].create("asturias", "Spain", sf::Vector2f(774, 4065), mapSprite.getPosition(), sf::Color(255, 50, 71), "wood", "catholic");
	provinces[30].create("galicia", "Spain", sf::Vector2f(624, 4059), mapSprite.getPosition(), sf::Color(48, 100, 255), "grain", "catholic");
	provinces[31].create("madrid", "Spain", sf::Vector2f(1014, 4299), mapSprite.getPosition(), sf::Color(76, 255, 121), "textiles", "catholic");
	provinces[32].create("castillalamancha", "Spain", sf::Vector2f(930, 4305), mapSprite.getPosition(), sf::Color(183, 112, 255), "grain", "catholic");
	provinces[33].create("extremadura", "Spain", sf::Vector2f(804, 4389), mapSprite.getPosition(), sf::Color(255, 203, 119), "textiles", "catholic");
	provinces[34].create("andalucia", "Spain", sf::Vector2f(789, 4560), mapSprite.getPosition(), sf::Color(170, 0, 255), "wine", "catholic");
	provinces[35].create("murcia", "Spain", sf::Vector2f(1164, 4560), mapSprite.getPosition(), sf::Color(0, 76, 255), "grain", "catholic");


	countries[0].init("France", "paris", 100);


	for (int i = 0; i < PROVINCE_COUNT; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			if (countries[j].army.getLocation() == provinces[i].getID())
			{
				provinces[i].hasArmy = true;
			}
			else
			{
				provinces[i].hasArmy = false;
			}
		}
	}

	changeMapMode(1); //political as default mapmode

	std::cout << "done.\n";

}



void World::handleStateChange(sf::Time dt)
{
	int speed = 1200;

	//keeps the game view below the very top of the map
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (mapView.getCenter().y - mapView.getSize().y / 2.0 >= mapSprite.getPosition().y)
		{
			mapView.move(sf::Vector2f(0, -speed * dt.asSeconds()));
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (mapView.getCenter().x - mapView.getSize().x / 2.0 >= mapSprite.getPosition().x)
		{
			mapView.move(sf::Vector2f(-speed * dt.asSeconds(), 0));
		}
	}

	//corrects the game view if it happens to be one frame's worth above the map (guaranteed to happen every time)
	if (mapView.getCenter().y - mapView.getSize().y / 2.0 < mapSprite.getPosition().y)
	{
		mapView.move(sf::Vector2f(0, mapSprite.getPosition().y - (mapView.getCenter().y - mapView.getSize().y / 2.0)));
	}

	//corrects the game view if it happens to be one frame's worth to the left the map (guaranteed to happen every time)
	if (mapView.getCenter().x - mapView.getSize().x / 2.0 < mapSprite.getPosition().x)
	{
		mapView.move(sf::Vector2f(mapSprite.getPosition().x - (mapView.getCenter().x - mapView.getSize().x / 2.0), 0));
	}


	//keeps the game view above the very bottom of the map
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (mapView.getCenter().y + mapView.getSize().y / 2 + speed * dt.asSeconds() <= mapSprite.getTextureRect().height)
		{
			mapView.move(0, speed * dt.asSeconds());
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (mapView.getCenter().x + mapView.getSize().x / 2 + speed * dt.asSeconds() <= mapSprite.getTextureRect().width)
		{
			mapView.move(speed * dt.asSeconds(), 0);
		}
	}


}

void World::handleKbdEvent(sf::Event evnt)
{
	//handle game logic first

	if (evnt.key.code == sf::Keyboard::Num1)
	{
		changeMapMode(1);
	}

	if (evnt.key.code == sf::Keyboard::Num2)
	{
		changeMapMode(2);
	}

	if (evnt.key.code == sf::Keyboard::Num3)
	{
		changeMapMode(3);
	}

	if (evnt.key.code == sf::Keyboard::Num4)
	{
		changeMapMode(4);
	}

	if (evnt.key.code == sf::Keyboard::Num5)
	{
		changeMapMode(5);
	}

	if (evnt.key.code == sf::Keyboard::Num6)
	{
		changeMapMode(6);
	}

	if (evnt.key.code == sf::Keyboard::G)
	{
		shown = !shown;
	}


	//handle HUD logic 

	if (evnt.key.code == sf::Keyboard::Tilde)
	{
		debugMode = !debugMode;

		if (debugMode)
		{
			hudText[DEBUG_TOGGLE].set("Debug mode: on");
		}
		else
		{
			hudText[DEBUG_TOGGLE].set("Debug mode: off");
		}
	}

	if (evnt.key.code > 26 && evnt.key.code < 35)
	{
		hudText[CURRENT_MAPMODE].set("Current mapmode: " + getMapMode());
	}


}

void World::handleMouseEvent(sf::Vector2i pos, std::string button)
{
	sf::Vector2f worldPos = windowPtr->mapPixelToCoords(pos);

	if (button == "mouse_left")
	{

		setProvinceClicked(pos);

		provSelectedInfoStr = getProvinceClicked();

		selectedProvinceText[0].set("ID: " + provSelectedInfoStr[0]);
		selectedProvinceText[1].set("Owner: " + provSelectedInfoStr[1]);
		selectedProvinceText[2].set("Resource: " + provSelectedInfoStr[2]);
		selectedProvinceText[3].set("Religion: " + provSelectedInfoStr[3]);

		hudText[PROVINCE_SELECTED_NAME].set("Province name: " + provSelectedInfoStr[0]);



		if (hudText[CURRENT_MAPMODE].getString() == "Current mapmode: political")
		{
			hudText[MAPMODE_DATA].set(selectedProvinceText[1].getString());
		}
		else if (hudText[CURRENT_MAPMODE].getString() == "Current mapmode: resource")
		{
			hudText[MAPMODE_DATA].set(selectedProvinceText[2].getString());
		}
		else
		{
			hudText[MAPMODE_DATA].set("NULL");
		}
		provinceMenu.set(provSelectedInfoStr[0]);
		sf::FloatRect menuRect = provinceMenu.getBounds();
		provinceMenu.setPos(worldPos + sf::Vector2f(7.f, -30.f) - sf::Vector2f(menuRect.width / 2.0, menuRect.height / 2.0));

	}

	else if (button == "mouse_right")
	{
		if (countries[0].army.isSelected)
		{
			setArmyDestination(pos);
		}
	}

}

void World::updateCursor(sf::RenderWindow* wnd)
{
	sf::Vector2i mouseScrnCoords = sf::Mouse::getPosition(*wnd);
	cursorSprite.setPosition((sf::Vector2f)mouseScrnCoords);
}

void World::setProvinceClicked(sf::Vector2i mousePos)
{
	sf::Color col = provinceColorMap.getPixel(mousePos.x, mousePos.y);

	bool found = false;

	for (int i = 0; i < PROVINCE_COUNT; i++)
	{
		//reset all province selection
		provinces[i].isSelected = false;

		if (!found)
		{
			if (col == provinces[i].getColID())
			{
				provinces[i].isSelected = true;
				selectedProvinceText[0].set(provinces[i].getID());
				selectedProvinceText[1].set(provinces[i].getOwner());
				selectedProvinceText[2].set(provinces[i].getResource());
				selectedProvinceText[3].set(provinces[i].getReligion());
				found = true;

				if (provinces[i].armyZone.getGlobalBounds().contains(mousePos.x, mousePos.y))
				{
					if (provinces[i].hasArmy)
					{
						countries[0].army.isSelected = true;
						std::cout << "army clicked!\n";
					}
				}
				else
				{
					countries[0].army.isSelected = false;
				}
			}
		}

		provinces[i].updateSelected();

	}

	if (!found)
	{
		selectedProvinceText[0].set("");
		selectedProvinceText[1].set("");
		selectedProvinceText[2].set("");
		selectedProvinceText[3].set("");
	}

}

void World::setArmyDestination(sf::Vector2i mousePos)
{
	sf::Color col = provinceColorMap.getPixel(mousePos.x, mousePos.y);

	bool found = false;

	for (int i = 0; i < PROVINCE_COUNT; i++)
	{
		provinces[i].hasArmy = false;
		provinces[i].isSelected = false;

		if (!found)
		{
			if (col == provinces[i].getColID())
			{
				found = true;
				provinces[i].hasArmy = true;
				countries[0].army.setLocation(provinces[i].getID());
			}
			else
			{
				provinces[i].hasArmy = false;
			}
		}
		provinces[i].updateSelected();
	}

}

std::vector<std::string> World::getProvinceClicked()
{
	std::vector<std::string> vec;
	vec.push_back(selectedProvinceText[0].getString());
	vec.push_back(selectedProvinceText[1].getString());
	vec.push_back(selectedProvinceText[2].getString());
	vec.push_back(selectedProvinceText[3].getString());

	return vec;
}


std::string World::getMapMode()
{
	return mapmode;
}

void World::changeMapMode(int mode)
{
	switch (mode)
	{
	case 1:
		mapmode = "political";
		break;
	case 2:
		mapmode = "resource";
		break;
	case 3:
		mapmode = "population";
		break;
	case 4:
		mapmode = "revenue";
		break;
	case 5:
		mapmode = "religion";
		break;
	case 6:
		mapmode = "ethnicity";
		break;
	default:
		break;
	}

	for (int i = 0; i < PROVINCE_COUNT; i++)
	{
		provinces[i].setMapMode(mode);
	}
}

void World::receiveDateUpdate(float newDate)
{
	std::string te = std::to_string((int)newDate);
	hudText[DATE].set("Day: " + te);
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	//map drawing
	target.setView(mapView);

	target.draw(mapSprite);


	if (shown)
	{
		for (int i = 0; i < PROVINCE_COUNT; i++)
		{
			target.draw(provinces[i]);
		}


	}

	target.draw(provinceMenu);


	//hud drawing
	target.setView(hudView);




	target.draw(hudText[DEBUG_TOGGLE]);
	target.draw(hudText[VERSION_HEADER]);
	target.draw(hudText[CURRENT_MAPMODE]);
	target.draw(hudText[MAPMODE_DATA]);
	target.draw(hudText[PROVINCE_SELECTED_NAME]);
	target.draw(hudText[DATE]);
	target.draw(hudText[GAME_STATE]);

	target.draw(cursorSprite);
}

World::~World()
{

}