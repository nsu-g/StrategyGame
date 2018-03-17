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
}

void Finite_State_Machine::click(sf::Vector2i Position)
{
	switch (Current_State)
	{
	case Global_Screen:
		The_Renderer->Find_The_Chosen_Hex(Position.x,Position.y); //ищем выделенный гексагон.

		if (The_Renderer->Is_A_Hex_Active() == true)
		{
			Current_State = Global_Screen_Unit_Selected;
		} //если мы щёлкнули на гексагон, то мы переходим в состояние "Выделен Юнит". БУДЕТ ИЗМЕНЕНОБ КОГДА Я СМОГУ ПОЛУЧИТЬ ДОСТУП К ЮНИТАМ И ПРОВЕРЯТЬ, ЩЁЛКНУЛИ МЫ НА ЮНИТА.
		
		break;

	case Global_Screen_Unit_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y); //ищем новый выделенный гексагон.

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
		} //если мы щёлкнули на область вне поля гексагонов, то выделение с текущего гексагона нажно убрать, мы переходим в состояние "Глобальный экран".
		
		break;

	case Global_Screen_Town_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y);

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
		} //если мы щёлкнули на область вне поля гексагонов, то выделение с текущего гексагона нажно убрать, мы переходим в состояние "Глобальный экран".
		
		break;
	} //Стоит иметь ввиду, что это только зачаточное состояние конечного автомата, но я пока не знаком с результатами работ драгих команд, так что не могу корректно разделить состояния "Выделен юнит" и "Выделен город".
}
