#include "City.h"
#include <fstream>
class City;

void City::render(sf::RenderTarget& r)
{
	this->get_texture().loadFromFile("Textures/City 66x69 Real_Size.png"); //This picture was supposed to be larger. But I have not drawn whole picture.
	this->get_texture().setSmooth(false);
	this->get_sprite().setTexture(get_texture());
	this->get_sprite().setScale(sf::Vector2f(1, 1));
	this->get_sprite().setOrigin(33, 60); //X-coordinate of the sprite is set to the centre of the picture, Y-coordinat is a little bit upper its bottom.

	WorldController* wc = WorldController::Get_The_Controller_Instance();

	this->get_sprite().setPosition(wc->mapToScreen(pos));

	r.draw(this->get_sprite());
}

void City::update()
{

}

std::vector<int> City::dwellers()
{
	return this->dw;
}

float City::faith()
{
	return this->relig;
}

std::vector<float> City::kill()
{
	return this->murder;
}

void City::save(std::ofstream& fout)
{
	std::string name = "City";
	this->save_me(fout, name);
	//fout << "dwellers:" << this->dwellers() << '\t';
	//fout << "murder:" << this->kill() << '\t';
	//fout << "faith:" << this->faith() << '\t';
}