#pragma once

#include <vector>
#include "SFML/Graphics.hpp"

#include "WorldController.h"
#include "WorldModel.h"
#include "WorldRenderer.h"

//����� ����� ��������� ��� ��������� ��������

class Finite_State_Machine
{
private:
	
	Finite_State_Machine()
	{
	}

	enum States
	{
		Global_Screen,
		Global_Screen_Unit_Selected,
		Global_Screen_Townn_Selected
	};



	States Current_State = Global_Screen;

public:

};