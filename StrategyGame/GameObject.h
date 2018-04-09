#pragma once
#include <fstream>
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
	
	virtual sf::Vector2u& position();

	virtual sf::Vector2u& loc_position();
	
	virtual sf::Sprite& get_sprite();

	virtual sf::Texture& get_texture();

	virtual bool get_active();

	virtual void set_active(bool new_active);

	virtual void save_me(std::ofstream fout, std::string type_object);
};
