#include "GameObject.h"
#include "City.h"
#include <fstream>
class City;

sf::Vector2u& GameObject::position()
{
	return pos;
}

sf::Vector2u & GameObject::loc_position()
{
	auto& world = WorldModel::getWorldInstance()->landscape;
	for (int i = 0; i < world.size(); i++)
	{
		if (world[i]->position() == this->position())
		{
			City* pf = dynamic_cast<City*>(&(*(world[i])));
			if (pf != nullptr)
			{
				if (this->position() == pf->position()) return this->loc_pos;
			}
		}
	}
	return this->position();
}

sf::Sprite& GameObject::get_sprite()
{
	return sprite;
}

sf::Texture& GameObject::get_texture()
{
	return texture;
}

bool GameObject::get_active()
{
	return active;
}

void GameObject::set_active(bool new_active)
{
	this->active = new_active;
}

void GameObject::save_me(std::ofstream fout, std::string type_object)
{
	fout << type_object << '\t';
	fout << this->position().x + ' ' + this->position().y << '\t';
	fout << this->loc_position().x + ' ' + this->loc_position().y << '\t';
}