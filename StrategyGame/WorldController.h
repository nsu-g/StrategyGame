#pragma once

#include <SFML\System.hpp>
#include "Student.h"
//TODO : Singleton
class Student;

class WorldController
{
	const float pi = 3.14159265358979323846;

	unsigned int offset_x;
	unsigned int offset_y;
	float hex_radius;
	float hex_width;
	float hex_h;
public:
	WorldController(unsigned int offset_x, unsigned int offset_y, float hex_radius) :
		offset_x(offset_x),
		offset_y(offset_y),
		hex_radius(hex_radius)
	{
		hex_width = hex_radius * 2 * cos(30 * pi / 180.0f);
		hex_h = hex_radius * sin(30 * pi / 180.0f);
	}


	sf::Vector2f mapToScreen(sf::Vector2u point)
	{
		if (point.y % 2 == 0)
		{
			return {offset_x+hex_width*point.x, offset_y+ (hex_radius + hex_h) * 2*(point.y)/2};
		} else {
			return { offset_x + hex_width/2 + hex_width*point.x, 
				offset_y + hex_radius+hex_h + (hex_radius + hex_h) * 2 * (point.y-1)/2 }; 
		}
	}

	bool move(GameObject& go, sf::Vector2i direction)
	{
		// TODO: check for direction length, other objects from WorldModel don't lie in that coord
		// return true if success
	}

	bool attack(GameObject& go, sf::Vector2i direction)
	{
		return true;
		// TODO: check for direction length, other objects from WorldModel don't lie in that coord
		// return true if success
		//WorldController::getControllerInstance()->attack(*this, {1,1});
	}

	bool attack(Student& go, sf::Vector2i direction)
	{
		return true;
		// TODO: check for direction length, other objects from WorldModel don't lie in that coord
		// return true if success
	}

	std::vector<std::shared_ptr<GameObject>> getNearActors(GameObject& go)
	{
		return{};
	}

	std::vector<std::shared_ptr<GameObject>> getNearLandscape(GameObject& go)
	{
		return{};
	}

	//TODO: handle all updates, delete orders that are finished, delete unnecessary objects
	void update()
	{

	}


};