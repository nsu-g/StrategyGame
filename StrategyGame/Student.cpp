#include "Student.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "Actors.h"

class WorldController;
class Actors;
class Student;
void Student::render(sf::RenderTarget& r)
{
	texture1.loadFromFile("Sm_bolter_hero_2.png");
	space.setTexture(texture1);
	space.setScale(sf::Vector2f(0.1, 0.1));
	
	WorldController wc(30, 30, 20);

	space.setPosition(wc.mapToScreen(pos));

	r.draw(space);
}


void Student::update()
{
	
	/*
	for (int i = 0; i < 10000000; i++)
	{
		i++;
	}
		{
			pos.x = pos.x + 1;
			pos.y = pos.y + 1;
		}
		std::shared_ptr<Student> subj;
		auto Ord = std::make_shared<WorldController>();
	sf::Vector2u endPosition = { 5,1 };
	std::vector<sf::Vector2i> VectorOfElementalMovement = Student::ABMovement(endPosition);
	
	for (int i = 0; i < VectorOfElementalMovement.size(); i++)
	{
		
		auto some = Ord->move(subj,VectorOfElementalMovement[i]);

		if (some ==true)
		{
			VectorOfElementalMovement.erase(VectorOfElementalMovement.begin() + i);
			i--; // deleted element, elements shifted
		}
		
	}
	*/

}