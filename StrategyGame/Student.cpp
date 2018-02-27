#include "Student.h"

void Student::render(sf::RenderTarget& r)
{
	sf::CircleShape shape;
	shape.setRadius(17);
	shape.setFillColor(sf::Color::Red);
	WorldController wc(30, 30, 20);
	shape.setPosition(wc.mapToScreen(pos) - sf::Vector2f(17, 17));
	r.draw(shape);
}

void Student::update()
{
	if (pos.x == 0)
		pos = { 1, 1 };
	else 
		pos = { 0, 0 };
}