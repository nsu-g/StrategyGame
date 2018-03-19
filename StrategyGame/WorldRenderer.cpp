#include "WorldRenderer.h"

WorldRenderer* WorldRenderer::RENDERER = nullptr;

WorldRenderer * WorldRenderer::Get_The_Renderer_Instance()
{
	if (RENDERER != nullptr)
		return RENDERER;
	return RENDERER = new WorldRenderer();
}

void WorldRenderer::render_Global_Screen(sf::RenderTarget & renderer)
{
	renderGrid(renderer);
	for (auto& i : WorldModel::getWorldInstance()->actors)
	{
		//i->render(renderer);
	}
}

void WorldRenderer::Find_The_Chosen_Hex(float x, float y)
{
	float x_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*cos(60 * pi / 180.f); //��� �������� �� ����� ������� ����� ��� ���� ����� ������� ������ ������������� � ���� �� ����� ��� ������ ��� �����.
	float y_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*sin(60 * pi / 180.f); //��� �������� �� ����� ������� ������ ��� ���� ����� ������� ������ ������������� � ���� �� ����� ��� ����.

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			float CurrentHex_Center_X = 30 - (i % 2) * x_offset + j * (2 * radius * cos(30 * pi / 180.f) - 1);
			float CurrentHex_Center_Y = 30 + i * y_offset;

			if ((abs(x - CurrentHex_Center_X) <= radius*cos(30 * pi / 180.f)) &&
				(abs(y - CurrentHex_Center_Y) <= radius - abs(x - CurrentHex_Center_X) / sqrt(3)))
			{
				Chosen_Hex = sf::Vector2i(j, i); //������ � ����� �������, ��� ��� j - ����� ������� � �������, ������ ���������� �� X.
				A_Hex_Is_Active = 1; //���� �� ����� ��������, �� ������� ��������, �� ���� ��� ��������.
				return;
			}
			else {A_Hex_Is_Active = 0;} //���� ��� �� ����� ���������� ��������. ������������, ��� �� �������� � ������� ��� ����.
		}
	}
	return;
}

void WorldRenderer::render_The_ChosenHex(sf::RenderTarget & renderer)
{
	float x_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*cos(60 * pi / 180.f); //��� �������� �� ����� ������� ����� ��� ���� ����� ������� ������ ������������� � ���� �� ����� ��� ������ ��� �����.
	float y_offset = (2 * radius*cos(30 * pi / 180.f) - 1)*sin(60 * pi / 180.f); //��� �������� �� ����� ������� ������ ��� ���� ����� ������� ������ ������������� � ���� �� ����� ��� ����.

	renderGreenHex(30 - (Chosen_Hex.y % 2) * x_offset + Chosen_Hex.x * (2 * radius * cos(30 * pi / 180.f) - 1), 30 + Chosen_Hex.y * y_offset, renderer);
}

bool WorldRenderer::Is_A_Hex_Active()
{
	return A_Hex_Is_Active;
}

