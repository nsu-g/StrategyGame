#include "Student.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"

class WorldController;

void Student::render(sf::RenderTarget& r)
{
	texture1.loadFromFile("Sm_bolter_hero_2.png");
	space_marine.setTexture(texture1);
	space_marine.setScale(sf::Vector2f(0.1, 0.1));
	
	WorldController wc(30, 30, 20);

	space_marine.setPosition(wc.mapToScreen(pos));

	r.draw(space_marine);
}

std::vector<sf::Vector2i> Student::ABMovement(sf::Vector2u endPosition)
{
    
	std::vector<sf::Vector2i> StepsVector;
	sf::Vector2i direction = {0,0};
	direction.x = endPosition.x;
	direction.y = endPosition.y;

	int x0;
	int y0;
	int xf;
	int yf;
	double a;
	double Len;
	double MinDistance;

	x0 = pos.x;
	y0 = pos.y;
	xf = endPosition.x;
	yf = endPosition.y;

	while (x0 != xf && y0 != yf)
	{
		MinDistance = sqrt(pow((x0 - xf), 2) + pow((y0 - yf), 2));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{

				sf::Vector2i IterHex = { x0 - 1 + i,y0 - 1 + j };

				a = (IterHex.y - y0) / (IterHex.x - x0);
				Len = (pow(IterHex.x - (x0 + IterHex.x + a*(y0 - IterHex.y) + sqrt(pow(x0 + xf + a*(y0 - IterHex.y), 2) - 4 * (1 + a)*(x0*IterHex.x))) / (2 * (1 + a)), 2) +
					+pow(IterHex.y - y0 + a*((x0 + IterHex.x + a*(y0 - IterHex.y) + sqrt(pow(x0 + IterHex.x + a*(y0 - IterHex.y), 2) - 4 * (1 + a)*(x0*IterHex.x))) / (2 * (1 + a))), 2));

				if (MinDistance > Len)
				{
					MinDistance = Len;
					direction.x = IterHex.x;
					direction.y = IterHex.y;
				}

			}
		}
		StepsVector.push_back(direction);
		x0 = x0 + direction.x;
		y0 = y0 + direction.y;
	}
	return(StepsVector);
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