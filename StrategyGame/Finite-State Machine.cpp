#include "Finite-State Machine.h"
#include <iostream>

void Finite_State_Machine::render()
{
	The_Controller->update();
	The_Renderer->render_Global_Screen(The_Target);
	if (The_Renderer->Is_A_Hex_Active() == true)
	{
		The_Renderer->render_The_ChosenHex(The_Target); //Render the chosen hexagon in order to check ih the code is working.
	}
	The_Model->Render_Actors(The_Target); //Render all actors.
	The_Model->Render_Landscapes(The_Target); //Render all landscapes.
	The_Interface.render(The_Target); //Render the interface.
	std::cout << Current_State << std::endl;
}

void Finite_State_Machine::click(sf::Vector2i Position) //Transition from the "Activated" states is not written!!!
{
	switch (Current_State)
	{
	case Global_Screen:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y); //Let's search the hexagon where we clicked.

		if (The_Renderer->Is_A_Hex_Active() == true) //If we've really clcked a hexagon. do the following:
		{
			for (int i = 0; i < The_Model->landscape.size(); i++) //Go through all "landscapes".
			{
				if (The_Model->landscape[i]->position() == The_Renderer->Get_The_Chosen_Hex())
				{
					The_Model->landscape[i]->set_active(true); //The chosen landscape becomes active;
					Current_State = Global_Screen_Town_Selected;
					return; //If the chosen hexagon's position coincides with the position of any "landscape", change the Current_State to "a town selected".
				}
			}
			for (int i = 0; i < The_Model->actors.size(); i++) //Go through all "actors".
			{
				if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
				{
					The_Model->actors[i]->set_active(true); //The chosen actor becomes active;
					Current_State = Global_Screen_Unit_Selected;
					return; //If the chosen hexagon's position coincides with the position of any "actor", change the Current_State to "a unit selected".
				}
			}
		}

		break;

	case Global_Screen_Unit_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y); //Let's search the hexagon where we clicked.

		int The_Chosen_Unit;

		for (int i = 0; i < The_Model->actors.size(); i++) //Go through all "actors".
		{
			if (The_Model->actors[i]->get_active() == true)
			{
				The_Chosen_Unit = i;
				break;
			}
		} //We'd like to remember which unit is "active" now.

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			The_Model->actors[The_Chosen_Unit]->set_active(false);
			Current_State = Global_Screen;
			return;
		} //If we clicked anywhere out of the hexagon field we "deactivate" the chosen actor and return to the "global screen" state.

		else //If we've really clcked a hexagon. do the following:
		{
			for (int i = 0; i < The_Model->landscape.size(); i++) //Go through all "landscapes".
			{
				if (The_Model->landscape[i]->position() == The_Renderer->Get_The_Chosen_Hex())
				{
					The_Model->actors[The_Chosen_Unit]->set_active(false); //"Deactivate" the chosen unit.
					The_Model->landscape[i]->set_active(true); //The chosen landscape becomes active.
					Current_State = Global_Screen_Town_Selected;
					return; //If the chosen hexagon's position coincides with the position of any "landscape", change the Current_State to "a town selected".
				}
			}
			for (int i = 0; i < The_Model->actors.size(); i++) //Go through all "actors".
			{
				if (The_Model->actors[i]->position() == The_Renderer->Get_The_Chosen_Hex())
				{
					if (i == The_Chosen_Unit)
					{
						Current_State = Global_Screen_Unit_Activated;
						return; //If we once again clicked on the same unit, we should change the Current_State to "a unit activated".
					}
					else
					{
						The_Model->actors[The_Chosen_Unit]->set_active(false); //"Deactivate" the chosen unit.
						The_Model->actors[i]->set_active(true); //The chosen actor becomes active;
						Current_State = Global_Screen_Unit_Selected;
						return; //If the chosen hexagon's position coincides with the position of any "actor", change the Current_State to "a unit selected".
					}
				}
			}
			The_Model->actors[The_Chosen_Unit]->set_active(false);
			Current_State = Global_Screen; //If there is no 'landscape" and no "actor" in the hexagon where we clicked, "deactivate" the chosen unit and return to the "global screen" state.
		}
		break;

	case Global_Screen_Town_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y);

		int The_Chosen_Landscape;

		for (int i = 0; i < The_Model->landscape.size(); i++) //Go through all "actors".
		{
			if (The_Model->landscape[i]->get_active() == true)
			{
				The_Chosen_Landscape = i;
				break;
			}
		} //We'd like to remember which unit is "active" now.

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			The_Model->landscape[The_Chosen_Landscape]->set_active(false);
			Current_State = Global_Screen;
			return;
		} //If we clicked anywhere out of the hexagon field we "deactivate" the chosen landscape and return to the "global screen" state.

		else //If we've really clcked a hexagon. do the following:
		{
			for (int i = 0; i < The_Model->landscape.size(); i++) //Go through all "landscapes".
			{
				if (The_Model->landscape[i]->position() == The_Renderer->Get_The_Chosen_Hex())
				{
					if (The_Model->landscape[i]->position() == The_Renderer->Get_The_Chosen_Hex())
					{
						if (i == The_Chosen_Landscape)
						{
							Current_State = Global_Screen_Town_Activated;
							return; //If we once again clicked on the same landscape, we should change the Current_State to "a town activated".
						}
						else
						{
							The_Model->landscape[The_Chosen_Landscape]->set_active(false); //"Deactivate" the chosen landscape;
							The_Model->landscape[i]->set_active(true); //The chosen landscape becomes active.
							Current_State = Global_Screen_Town_Selected;
							return; //If the chosen hexagon's position coincides with the position of any "landscape", change the Current_State to "a town selected".
						}
					}
				}
				for (int i = 0; i < The_Model->actors.size(); i++) //Go through all "actors".
				{
					if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
					{
						The_Model->landscape[The_Chosen_Landscape]->set_active(false); //"Deactivate" the chosen landscape;
						The_Model->actors[i]->set_active(true); //The chosen actor becomes active;
						Current_State = Global_Screen_Unit_Selected;
						return; //If the chosen hexagon's position coincides with the position of any "actor", change the Current_State to "a unit selected".
					}
				}
				The_Model->landscape[The_Chosen_Landscape]->set_active(false); //"Deactivate" the chosen landscape;
				Current_State = Global_Screen; //If there is no 'actors" and no "landscape" in the hexagon where we clocked, return to the "global screen" state.
			}
			break;
		}
		The_Interface.update(); //Update the interface.
	}
}
