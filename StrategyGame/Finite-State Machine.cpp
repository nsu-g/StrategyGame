#include "Finite-State Machine.h"
#include <iostream>

void Finite_State_Machine::render()
//НЕ ПРОПИСАНО: АДЕКВАТНАЯ ПРОРИСОВКА ЮНИТОВ И ГОРОДОВ, ЕСЛИ ТАКИЕ БУДУТ.
{
	switch (Current_State)
	{
		case Global_Screen:
			The_Controller->update();
			The_Renderer->render_Global_Screen(The_Target);
			if (The_Renderer->Is_A_Hex_Active() == true)
			{
				The_Renderer->render_The_ChosenHex(The_Target); //чтобы хоть как-то отслеживать работоспособность кода
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
		The_Renderer->Find_The_Chosen_Hex(Position.x,Position.y); //ищем выделенный гексагон.

		if (The_Renderer->Is_A_Hex_Active() == true) //если мы щёлкнули на какой-то гекс, то делай это:
		{
			for (int i = 0; i < The_Model->actors.size(); i++) //прбегаемся по всем "Актёрам".
			{
				if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Unit_Selected;
					return; //если выделенный гекс совпадает с позицией какого-то из "актёров", то переходи в состояние "Выделен юнит".
				}
			}
			for (int i = 0; i < The_Model->landscape.size(); i++)
			{
				if (The_Model->landscape[i]->position().x == Position.x && The_Model->landscape[i]->position().y == Position.y) //странный синтаксис, но по-другому не смог.
				{
					Current_State = Global_Screen_Town_Selected;
					return; //если выделенный гекс совпадает с позицией какого-то из "ландшафтов", то переходи в состояние "Выделен город".
				}
			}
		}
		
		break;

	case Global_Screen_Unit_Selected: //НЕ УЧИТЫВАЕТСЯ ВОЗСОЖНОСТЬ ПЕРЕДВИЖЕНИЯ!!! ТОЛЬКО МЕНЯЕСТЯ ВЫДЕЛЕНИЕ!!!
		//НЕЛЬЗЯ ПЕРЕКЛЮЧИТЬСЯ С ЮНИТА НА ЮНИТ, С ГОРОДА НА ГОРОД
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y); //ищем новый выделенный гексагон.

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
			return;
		} //если мы щёлкнули на область вне поля гексагонов, то выделение с текущего гексагона нажно убрать, мы переходим в состояние "Глобальный экран".
		else //если всё-таки щёлкнули внутрь поля гексагонов
		{
			for (int i = 0; i < The_Model->landscape.size(); i++)
			{
				if (The_Model->landscape[i]->position().x == Position.x && The_Model->landscape[i]->position().y == Position.y) //странный синтаксис, но по-другому не смог.
				{
					Current_State = Global_Screen_Town_Selected;
					return; //если выделенный гекс совпадает с позицией какого-то из "ландшафтов", то переходи в состояние "Выделен город".
				}
			}
			Current_State = Global_Screen; //если же ни один город не находится там, куда ткнули, то переходи в сотояние "Глобальная карта".
		}
		break;

	case Global_Screen_Town_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y);

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
			return;
		} //если мы щёлкнули на область вне поля гексагонов, то выделение с текущего гексагона нажно убрать, мы переходим в состояние "Глобальный экран".
		else //если всё-таки щёлкнули внутрь поля гексагонов
		{
			for (int i = 0; i < The_Model->actors.size(); i++) //прбегаемся по всем "Актёрам".
			{
				if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Unit_Selected;
					return; //если выделенный гекс совпадает с позицией какого-то из "актёров", то переходи в состояние "Выделен юнит".
				}
			}
			Current_State = Global_Screen; //если же ни один юнит не находится там, куда ткнули, то переходи в сотояние "Глобальная карта".
		}
		break;
	}
}
