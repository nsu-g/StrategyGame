#pragma once

#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"

#include "WorldController.h"
#include "WorldModel.h"
#include "WorldRenderer.h"

//Здесь будет заготовка для конечного автомата

class Finite_State_Machine
{
private:

	enum States
	{
		Global_Screen,
		Global_Screen_Unit_Selected,
		Global_Screen_Town_Selected
	};

	States Current_State = Global_Screen;

	WorldController* The_Controller = WorldController::Get_The_Controller_Instance();
	WorldRenderer* The_Renderer = WorldRenderer::Get_The_Renderer_Instance();
	WorldModel* The_Model = WorldModel::getWorldInstance();

	sf::RenderTarget& The_Target; //Скорее всего, это будет окно.

public:

	Finite_State_Machine(sf::RenderTarget& The_Target) : The_Target(The_Target)
	{
		auto New_Civilian = std::make_shared<Actors>(); //Let's create a new Actor in order to check our code.
		New_Civilian->position() = sf::Vector2u(2,2);
		The_Model->actors.push_back(New_Civilian);		
	}

	void render();
	void click(sf::Vector2i Position);
	
};