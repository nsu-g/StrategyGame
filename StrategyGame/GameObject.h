#pragma once

#include <SFML\Graphics.hpp>

//Abstract class which will be parent to other objects, has position, renders to image, updates when world changes
class GameObject
{
protected:
	sf::Vector2u loc_pos;
	sf::Vector2u pos;
	sf::Sprite sprite;
	sf::Texture texture;
	bool active = false;

public:
	virtual void render(sf::RenderTarget&) = 0;
	virtual void update() = 0;
	
	virtual sf::Vector2u& position()
	{
		return pos;
	}
	
	virtual sf::Vector2u& loc_position();
	

	virtual sf::Sprite& get_sprite()
	{
		return sprite;
	}
	
	virtual sf::Texture& get_texture()
	{
		return texture;
	}
	
	virtual bool get_active()
	{
		return active;
	}

	virtual void set_active(bool new_active)
	{
		this->active = new_active;
	}
};
