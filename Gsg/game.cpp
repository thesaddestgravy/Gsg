#include "game.h"




Game::Game(int sw, int sh)
{
	std::cout << "initializing window...";
	focus = true;

	gameState = GameState::PLAY;



	scrw = sw;
	scrh = sh;
	wnd.create(sf::VideoMode(scrw, scrh), "Frost", sf::Style::Titlebar | sf::Style::Close);
	wnd.setVerticalSyncEnabled(true);
	wnd.setMouseCursorVisible(false);
	icon.loadFromFile("res/icon.png");
	wnd.setIcon(32, 32, icon.getPixelsPtr());
	std::cout << "done.\n";

	//loading screen code goes here...
	sf::Sprite loadScreen;
	sf::Texture loadTex;
	loadTex.loadFromFile("res/loadscreen.png");
	loadScreen.setTexture(loadTex);
	wnd.draw(loadScreen);
	wnd.display();

	//HUD and game world initialization + asset loading goes here...
	world.init(scrw, scrh, &wnd);

}

void Game::run()
{
	dateTimer.restart();
	gameLoop();
}

void Game::gameLoop()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (wnd.isOpen())
	{
		processInput(timeSinceLastUpdate);
		timeSinceLastUpdate = timeSinceLastUpdate + clock.restart();

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate = timeSinceLastUpdate - timePerFrame;

			processInput(timePerFrame);
		}

		render();



	}
}

void Game::processInput(sf::Time dt)
{
	date = dateTimer.getElapsedTime().asSeconds();
	world.receiveDateUpdate(date);

	sf::Event evnt;

	while (wnd.pollEvent(evnt))
	{
		if (evnt.type == sf::Event::LostFocus)
		{
			focus = false;
			wnd.setMouseCursorVisible(true);
		}

		if (evnt.type == sf::Event::GainedFocus)
		{
			focus = true;
			wnd.setMouseCursorVisible(false);
		}

		if (focus)
		{
			eventHandler.execute(&sysKbd, &sysMouse, &evnt, &wnd, &world);
		}
	}


	//all real time inputs go here...
	if (focus)
	{
		world.handleStateChange(dt);
		world.updateCursor(&wnd);
	}
}


void Game::render()
{
	wnd.clear(sf::Color(30, 30, 30));

	wnd.draw(world);

	wnd.display();
}


Game::~Game()
{
}
