#include "Actors.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"

class WorldController;

void Actors::render(sf::RenderTarget& r)
{
	texture1.loadFromFile("Sm_bolter_hero_2.png");
	space.setTexture(texture1);
	space.setScale(sf::Vector2f(0.1, 0.1));

	WorldController wc(30, 30, 20);

	space.setPosition(wc.mapToScreen(pos));

	r.draw(space);
}

void Actors::update()
{
}