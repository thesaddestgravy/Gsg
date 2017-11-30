#include "event_handler.h"



EventHandler::EventHandler()
{
	focus = true;
}

void EventHandler::execute(sf::Keyboard* kbd, sf::Mouse* ms, sf::Event* evnt, sf::RenderWindow* wnd, World* world)
{

	sf::Vector2f mouseWorldPos = wnd->mapPixelToCoords(sf::Mouse::getPosition(*wnd), world->mapView);

	if (kbd->isKeyPressed(kbd->Escape))
	{
		wnd->close();
	}

	switch (evnt->type)
	{
	case sf::Event::Closed:
		wnd->close();
		break;

	case sf::Event::LostFocus:
		focus = false;
		break;

	case sf::Event::GainedFocus:
		focus = true;
		break;

	case sf::Event::MouseButtonPressed:
		if (focus)
		{
			if (evnt->mouseButton.button == ms->Left)
			{
				world->handleMouseEvent((sf::Vector2i)mouseWorldPos, "mouse_left");
			}

			if (evnt->mouseButton.button == ms->Right)
			{
				world->handleMouseEvent((sf::Vector2i)mouseWorldPos, "mouse_right");
			}
		}
		break;

	case sf::Event::KeyPressed:
		if (focus)
		{
			world->handleKbdEvent(*evnt);
		}
		break;

	default:
		break;
	}
}


EventHandler::~EventHandler()
{
}
