#include "Finite-State Machine.h"

void Finite_State_Machine::render()
{
	switch (Current_State)
	{
		case Global_Screen:
			The_Controller->update();
			The_Renderer->render_Global_Screen(The_Target);
			break;
		case Global_Screen_Unit_Selected:
			The_Controller->update();
			The_Renderer->render_Global_Screen_With_A_Hex_Selected(The_Target);
			break;
		case Global_Screen_Town_Selected:
			The_Controller->update();
			The_Renderer->render_Global_Screen_With_A_Hex_Selected(The_Target);
			break;
	}
}

void Finite_State_Machine::click(sf::Vector2i Position)
{
	switch (Current_State)
	{
	case Global_Screen:
		The_Renderer->Find_The_Chosen_Hex(Position.x,Position.y);
		Current_State = Global_Screen_Unit_Selected;
		break;
	case Global_Screen_Unit_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y);
		break;
	case Global_Screen_Town_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y);
		break;
	}
}
