#pragma once

#include "SFML/Graphics.hpp"

#include "WorldController.h"
#include "WorldModel.h"
#include "WorldRenderer.h"

//«десь будет заготовка дл€ конечного автомата

class Finite_State_Machine
{
private:

	enum States
	{
		Global_Screen,
		Global_Screen_Hex_Selected
	};

	sf::RenderWindow The_Window;

	WorldController The_Controller;
	WorldRenderer The_Renderer;

public:

};