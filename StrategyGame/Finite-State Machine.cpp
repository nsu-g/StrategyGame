#include "Finite-State Machine.h"
#include <iostream>

void Finite_State_Machine::render()
{
	switch (Current_State)
	{
		case Global_Screen:
			The_Controller->update();
			The_Renderer->render_Global_Screen(The_Target);
			if (The_Renderer->Is_A_Hex_Active() == true)
			{
				The_Renderer->render_The_ChosenHex(The_Target); //Render the chosen hexagon in order to check ih the code is working.
			}
			break;
		case Global_Screen_Unit_Selected:
			The_Controller->update();
			The_Renderer->render_Global_Screen(The_Target);
			if (The_Renderer->Is_A_Hex_Active() == true)
			{
				The_Renderer->render_The_ChosenHex(The_Target);
			}

			break;
		case Global_Screen_Town_Selected:
			The_Controller->update();
			The_Renderer->render_Global_Screen(The_Target);

			if (The_Renderer->Is_A_Hex_Active() == true)
			{
				The_Renderer->render_The_ChosenHex(The_Target);
			}

			break;
	}
	The_Model->Render_Actors(The_Target); //Render all actors.
	The_Model->Render_Landscapes(The_Target); //Render all landscapes.
}

void Finite_State_Machine::click(sf::Vector2i Position)
{
	switch (Current_State)
	{
	case Global_Screen:
		The_Renderer->Find_The_Chosen_Hex(Position.x,Position.y); //Let's search the hexagon where we clicked.

		if (The_Renderer->Is_A_Hex_Active() == true) //If we've really clcked a hexagon. do the following:
		{
			for (int i = 0; i < The_Model->landscape.size(); i++) //Go through all "landscapes".
			{
				if (The_Model->landscape[i]->position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Town_Selected;
					return; //If the chosen hexagon's position coincides with the position of any "landscape", change the Current_State to "a town selected".
				}
			}
			for (int i = 0; i < The_Model->actors.size(); i++) //Go through all "actors".
			{
				if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Unit_Selected;
					return; //If the chosen hexagon's position coincides with the position of any "actor", change the Current_State to "a unit selected".
				}
			}
		}
		
		break;

	case Global_Screen_Unit_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y); //Let's search the hexagon where we clicked.

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
			return;
		} //If we clicked anywhere out of the hexagon field we return to the "global screen" state.
		else //If we've really clcked a hexagon. do the following:
		{
			for (int i = 0; i < The_Model->landscape.size(); i++) //Go through all "landscapes".
			{
				if (The_Model->landscape[i]->position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Town_Selected;
					return; //If the chosen hexagon's position coincides with the position of any "landscape", change the Current_State to "a town selected".
				}
			}
			Current_State = Global_Screen; //If there is no 'landscape" in the hexagon where we clocked, return to the "global screen" state.
		}
		break;

	case Global_Screen_Town_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y);

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
			return;
		} //If we clicked anywhere out of the hexagon field we return to the "global screen" state.
		else //If we've really clcked a hexagon. do the following:
		{
			for (int i = 0; i < The_Model->actors.size(); i++) //Go through all "actors".
			{
				if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Unit_Selected;
					return; //If the chosen hexagon's position coincides with the position of any "actor", change the Current_State to "a unit selected".
				}
			}
			Current_State = Global_Screen; //If there is no 'actors" in the hexagon where we clocked, return to the "global screen" state.
		}
		break;
	}
}
