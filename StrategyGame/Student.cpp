#include "Student.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "Actors.h"

class WorldController;

void Student::render(sf::RenderTarget& r)
{
	this->get_texture().loadFromFile("Sm_bolter_hero_2.png");
	this->get_sprite().setTexture(get_texture());
	this->get_sprite().setScale(sf::Vector2f(0.1, 0.1));
	
	WorldController* wc = WorldController::Get_The_Controller_Instance();

	this->get_sprite().setPosition(wc->mapToScreen(pos));

	r.draw(this->get_sprite());

}


void Student::update()
{

}

void Student::save(std::ofstream & fout)
{
	std::string name = "Student";
	this->save_me(fout, name);
}