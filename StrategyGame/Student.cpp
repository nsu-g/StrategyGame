#include "Student.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "Actors.h"

class WorldController;

void Student::render(sf::RenderTarget& r)
{
	texture1.loadFromFile("Sm_bolter_hero_2.png");
	space.setTexture(texture1);
	space.setScale(sf::Vector2f(0.1, 0.1));
	
	WorldController* wc = WorldController::Get_The_Controller_Instance();

	space.setPosition(wc->mapToScreen(pos));

	r.draw(space);

}


void Student::update()
{

}