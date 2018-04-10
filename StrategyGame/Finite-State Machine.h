#pragma once

#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"

#include "WorldController.h"
#include "WorldModel.h"
#include "WorldRenderer.h"
#include "UI.h"

//The Finite-State Machine (later - the Machine) is declared here.

class Finite_State_Machine
{
private:

	enum States
	{
		Global_Screen,
		Global_Screen_Unit_Selected,
		Global_Screen_Landscape_Selected,
		Process_In_Progress,
		Global_Screen_Unit_Activated,
		Global_Screen_Landscape_Activated
	};

	States Current_State = Global_Screen;

	WorldController* The_Controller = WorldController::Get_The_Controller_Instance();
	WorldRenderer* The_Renderer = WorldRenderer::Get_The_Renderer_Instance();
	WorldModel* The_Model = WorldModel::getWorldInstance();

	sf::RenderTarget& The_Target; //This will be a window in our program.
	UI The_Interface = UI(The_Model);

public:

	Finite_State_Machine(sf::RenderTarget& The_Target) : The_Target(The_Target)
	{
		std::vector<std::shared_ptr<Civilian>> New_Civilians;
		New_Civilians.resize(8);

		for (int i = 0; i < New_Civilians.size(); i++)
		{
			New_Civilians[i] = std::make_shared<Civilian>();
			New_Civilians[i]->position() = sf::Vector2u(1 + i, 1 + i);
			New_Civilians[i]->add_hp(30 +5*i);
			The_Model->actors.push_back(New_Civilians[i]);
		} //Let's create several Civilians on the map to check our code.
		
		auto New_City = std::make_shared<City>(); //Let's create a new City in order to check our code.
		New_City->position() = sf::Vector2u(1, 7);
		The_Model->landscape.push_back(New_City);
	}

	void render();
	void click(sf::Vector2i Position);
	
};