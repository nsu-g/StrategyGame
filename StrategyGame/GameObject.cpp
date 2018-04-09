#include "GameObject.h"
#include "City.h"
class City;

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
