#pragma once
#include <string>
#include <vector>
#include <memory>

#include "GameObject.h"
#include "Order.h"
#include "Student.h"

class WorldModel {
	static WorldModel* WORLD;

	// Constructor is private so it can't be called from other code - Singletone pattern
	WorldModel();
	WorldModel(const WorldModel&) = delete;
	void operator=(const WorldModel&) = delete;
	
public:
	//TODO: move to private, add getters
	std::vector<std::shared_ptr<GameObject>> landscape;
	std::vector<std::shared_ptr<GameObject>> actors;
	std::vector<std::shared_ptr<Order>> orders;
	void LoadLevel(std::string filename)
	{
		//TODO load model from file. (For different game levels or save/load feature)
	}

	void SaveLevel(std::string filename)
	{
		//TODO save model to file
	}

	// static method HAS NO OBJECT, calls to class
	static WorldModel* getWorldInstance();

};

