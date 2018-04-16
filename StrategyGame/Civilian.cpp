#include "Civilian.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"

class WorldController;

void Civilian::render(sf::RenderTarget& r)
{
	this->get_texture().loadFromImage(The_Civilian_Image);
	this->get_texture().setSmooth(true);
	this->get_sprite().setTexture(get_texture());
	this->get_sprite().setScale(sf::Vector2f(0.3, 0.3));
	this->get_sprite().setOrigin(46, 149); //X-coordinate of the sprite is set to the centre of the picture, Y-coordinate - to its bottom.

	if (this->active == true)
	{
		this->get_sprite().setColor(sf::Color(200, 255, 200, 255)); //If this Civilian is "active" than we should highlight him somehow.
	}
	else
	{
		this->get_sprite().setColor(sf::Color(255, 255, 255, 255)); //If he is not "active" we should return him his original color.
	}

	WorldController* wc = WorldController::Get_The_Controller_Instance();

	this->get_sprite().setPosition(wc->mapToScreen(pos));

	r.draw(this->get_sprite());
}

void Civilian::update()
{

}

void Civilian::save(std::ofstream & fout)
{
	std::string name = "Civilian";
	this->save_me(fout, name);
}
