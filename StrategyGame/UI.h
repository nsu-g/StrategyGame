#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Actors.h"
#include "Finite-State Machine.h"
#include "WorldModel.h"
class UI
{
public:
	UI(WorldModel* The_Model)
	{
		this->The_Model = The_Model;
		update();

		//hp.setPoint(0, sf::Vector2f())
	}

	void update() {

		Actors actor;

		for (int i = 0; i < The_Model->actors.size(); i++)
		{
			if (The_Model->actors[i]->get_active() == true)
			{
				Actors actor = *The_Model->actors[i];

				hp.setPointCount(4);
				hp.setPoint(0, sf::Vector2f(10, 315));
				hp.setPoint(1, sf::Vector2f(10 + 2 * actor.health(), 315));
				hp.setPoint(2, sf::Vector2f(10 + 2 * actor.health(), 325));
				hp.setPoint(3, sf::Vector2f(10, 325));
				hp.setFillColor(sf::Color(255, 0, 0));

				faith.setPointCount(4);
				faith.setPoint(0, sf::Vector2f(10, 330));
				faith.setPoint(1, sf::Vector2f(10 + 2 * actor.faith(), 330));
				faith.setPoint(2, sf::Vector2f(10 + 2 * actor.faith(), 340));
				faith.setPoint(3, sf::Vector2f(10, 340));
				faith.setFillColor(sf::Color(0, 0, 255));

				break;
			}
			hp.setPointCount(4);
			hp.setPoint(0, sf::Vector2f(10, 315));
			hp.setPoint(1, sf::Vector2f(10, 315));
			hp.setPoint(2, sf::Vector2f(10, 325));
			hp.setPoint(3, sf::Vector2f(10, 325));
			hp.setFillColor(sf::Color(255, 0, 0));

			faith.setPointCount(4);
			faith.setPoint(0, sf::Vector2f(10, 330));
			faith.setPoint(1, sf::Vector2f(10, 330));
			faith.setPoint(2, sf::Vector2f(10, 340));
			faith.setPoint(3, sf::Vector2f(10, 340));
			faith.setFillColor(sf::Color(0, 0, 255));
		}

		rectangle.setPointCount(4);
		rectangle.setPoint(0, sf::Vector2f(5, 310));
		rectangle.setPoint(1, sf::Vector2f(305, 310));
		rectangle.setPoint(2, sf::Vector2f(305, 345));
		rectangle.setPoint(3, sf::Vector2f(5, 345));
		rectangle.setFillColor(sf::Color(245, 210, 55));

		hpText.setPosition(sf::Vector2f(0, 0));
		hpText.setString(std::to_string(actor.health()));
	}

	void render(sf::RenderTarget& target) {
		update();
		target.draw(rectangle);
		target.draw(hp);
		target.draw(faith);
		target.draw(hpText);
		target.draw(faithText);
	}

private:
	WorldModel* The_Model;
	sf::ConvexShape hp;
	sf::Text hpText;
	sf::ConvexShape faith;
	sf::Text faithText;
	sf::ConvexShape rectangle;
};