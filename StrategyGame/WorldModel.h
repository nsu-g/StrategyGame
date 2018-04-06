#pragma once
#include <string>
#include <vector>
#include <memory>

#include "GameObject.h"
#include "Order.h"
#include "MoveOrder.h"
#include "Actors.h"
#include "Student.h"
#include "Civilian.h"

#include "SFML/Graphics.hpp"

class Student;
class Civilian;
class Actors;

class WorldModel {
	static WorldModel* WORLD;

	// Constructor is private so it can't be called from other code - Singletone pattern
	WorldModel();
	WorldModel(const WorldModel&) = delete;
	void operator=(const WorldModel&) = delete;
	
public:

	//TODO: move to private, add getters
	std::vector<std::shared_ptr<GameObject>> landscape;
	std::vector<std::shared_ptr<Actors>> actors;
	std::vector<std::shared_ptr<Order>> orders;

	void LoadLevel(std::string filename)
	{
		//TODO load model from file. (For different game levels or save/load feature)
	}

	void SaveLevel(std::string filename);

	// static method HAS NO OBJECT, calls to class
	static WorldModel* getWorldInstance();

	//Render functions

	void Render_Actors(sf::RenderTarget& The_Target);
	void Render_Landscapes(sf::RenderTarget& The_Target);

};

