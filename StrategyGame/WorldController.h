#pragma once

#include <SFML\System.hpp>
#include "Student.h"
#include "WorldModel.h"
//TODO : Singleton
class Student;
class Civilian;
class Actors;
class WorldController
{
	const float pi = 3.14159265358979323846;

	unsigned int offset_x;
	unsigned int offset_y;
	float hex_radius;
	float hex_width;
	float hex_h;
public:
	// TODO: move hex-related methods to renderer
	WorldController(unsigned int offset_x, unsigned int offset_y, float hex_radius);


	sf::Vector2f mapToScreen(sf::Vector2u point);

	bool move(GameObject& go, sf::Vector2i direction);

	bool attack(GameObject& go, sf::Vector2i direction);

	bool attack(Student& go, sf::Vector2i direction);

	std::vector<std::shared_ptr<GameObject>> getNearActors(GameObject& go);

	std::vector<std::shared_ptr<GameObject>> getNearLandscape(GameObject& go);

	//TODO: handle all updates, delete orders that are finished, delete unnecessary objects
	void update();


};