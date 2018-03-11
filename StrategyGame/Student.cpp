#include "Student.h"
#include "WorldRenderer.h"

void Student::render(sf::RenderTarget& r)
{
	texture1.loadFromFile("Sm_bolter_hero_2.png");
	space_marine.setTexture(texture1);
	space_marine.setScale(sf::Vector2f(0.1, 0.1));
	
	WorldController wc(30, 30, 20);

	space_marine.setPosition(wc.mapToScreen(pos));

	r.draw(space_marine);
}

void Student::update()
{
	if (pos.x == 0)
		pos = { 1, 1 };
	else 
		pos = { 0, 0 };
}