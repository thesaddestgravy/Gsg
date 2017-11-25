#pragma once

#include <SFML/Graphics.hpp>

#include "world.h"

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	void execute(sf::Keyboard* kbd, sf::Mouse* ms, sf::Event* evnt, sf::RenderWindow* wnd, World* world);

private:
	bool focus;
};

