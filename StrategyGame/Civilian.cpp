#include "Civilian.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"

class WorldController;

void Civilian::render(sf::RenderTarget& r)
{
	this->get_texture().loadFromFile("Textures/Civilian 92x149 Real_Size.png"); //This picture was supposed to be a civilian. But I have not drawn other sprites yet.
	this->get_texture().setSmooth(true);
	this->get_sprite().setTexture(get_texture());
	this->get_sprite().setScale(sf::Vector2f(0.3, 0.3));
	this->get_sprite().setOrigin(46, 149); //X-coordinate of the sprite is set to the centre of the picture, Y-coordinat - to its bottom.

	WorldController* wc = WorldController::Get_The_Controller_Instance();

	this->get_sprite().setPosition(wc->mapToScreen(pos));

	r.draw(this->get_sprite());
}

void Civilian::update()
{

}