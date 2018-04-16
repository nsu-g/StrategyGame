#include "City.h"
#include <fstream>
class City;

void City::render(sf::RenderTarget& r)
{
	this->get_texture().loadFromImage(The_City_Image);
	this->get_texture().setSmooth(false);
	this->get_sprite().setTexture(get_texture());
	this->get_sprite().setScale(sf::Vector2f(1, 1));
	this->get_sprite().setOrigin(33, 60); //X-coordinate of the sprite is set to the centre of the picture, Y-coordinat is a little bit upper its bottom.

	if (this->active == true)
	{
		this->get_sprite().setColor(sf::Color(200, 255, 200, 255));
	}
	else
	{
		this->get_sprite().setColor(sf::Color(255, 255, 255, 255));
	}

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