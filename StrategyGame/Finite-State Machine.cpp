#include "Finite-State Machine.h"
#include <iostream>

void Finite_State_Machine::render()
//�� ���������: ���������� ���������� ������ � �������, ���� ����� �����.
{
	switch (Current_State)
	{
		case Global_Screen:
			The_Controller->update();
			The_Renderer->render_Global_Screen(The_Target);
			if (The_Renderer->Is_A_Hex_Active() == true)
			{
				The_Renderer->render_The_ChosenHex(The_Target); //����� ���� ���-�� ����������� ����������������� ����
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
		The_Renderer->Find_The_Chosen_Hex(Position.x,Position.y); //���� ���������� ��������.

		if (The_Renderer->Is_A_Hex_Active() == true) //���� �� �������� �� �����-�� ����, �� ����� ���:
		{
			for (int i = 0; i < The_Model->actors.size(); i++) //���������� �� ���� "������".
			{
				if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Unit_Selected;
					return; //���� ���������� ���� ��������� � �������� ������-�� �� "������", �� �������� � ��������� "������� ����".
				}
			}
			for (int i = 0; i < The_Model->landscape.size(); i++)
			{
				if (The_Model->landscape[i]->position().x == Position.x && The_Model->landscape[i]->position().y == Position.y) //�������� ���������, �� ��-������� �� ����.
				{
					Current_State = Global_Screen_Town_Selected;
					return; //���� ���������� ���� ��������� � �������� ������-�� �� "����������", �� �������� � ��������� "������� �����".
				}
			}
		}
		
		break;

	case Global_Screen_Unit_Selected: //�� ����������� ����������� ������������!!! ������ �������� ���������!!!
		//������ ������������� � ����� �� ����, � ������ �� �����
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y); //���� ����� ���������� ��������.

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
			return;
		} //���� �� �������� �� ������� ��� ���� ����������, �� ��������� � �������� ��������� ����� ������, �� ��������� � ��������� "���������� �����".
		else //���� ��-���� �������� ������ ���� ����������
		{
			for (int i = 0; i < The_Model->landscape.size(); i++)
			{
				if (The_Model->landscape[i]->position().x == Position.x && The_Model->landscape[i]->position().y == Position.y) //�������� ���������, �� ��-������� �� ����.
				{
					Current_State = Global_Screen_Town_Selected;
					return; //���� ���������� ���� ��������� � �������� ������-�� �� "����������", �� �������� � ��������� "������� �����".
				}
			}
			Current_State = Global_Screen; //���� �� �� ���� ����� �� ��������� ���, ���� ������, �� �������� � �������� "���������� �����".
		}
		break;

	case Global_Screen_Town_Selected:
		The_Renderer->Find_The_Chosen_Hex(Position.x, Position.y);

		if (The_Renderer->Is_A_Hex_Active() == false)
		{
			Current_State = Global_Screen;
			return;
		} //���� �� �������� �� ������� ��� ���� ����������, �� ��������� � �������� ��������� ����� ������, �� ��������� � ��������� "���������� �����".
		else //���� ��-���� �������� ������ ���� ����������
		{
			for (int i = 0; i < The_Model->actors.size(); i++) //���������� �� ���� "������".
			{
				if (The_Model->actors[i]->loc_position() == The_Renderer->Get_The_Chosen_Hex())
				{
					Current_State = Global_Screen_Unit_Selected;
					return; //���� ���������� ���� ��������� � �������� ������-�� �� "������", �� �������� � ��������� "������� ����".
				}
			}
			Current_State = Global_Screen; //���� �� �� ���� ���� �� ��������� ���, ���� ������, �� �������� � �������� "���������� �����".
		}
		break;
	}
}
