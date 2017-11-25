#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>

#include "world.h"
#include "dbg_str.h"
#include "event_handler.h"


enum class GameState { PLAY, PAUSE };


class Game
{
public:
	Game(int sw, int sh);
	~Game();

	void run();

private:
	void gameLoop();
	void processInput(sf::Time dt);


	void render();



	sf::RenderWindow wnd;
	GameState gameState;

	sf::Mouse sysMouse;
	sf::Keyboard sysKbd;

	World world;

	EventHandler eventHandler;
	bool focus;
	int scrw;
	int scrh;

	sf::Image icon;

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Clock dateTimer;
	float date;
};

