#pragma once

#include "GameObject.h"
#include "WorldController.h"
#include <SFML\Graphics.hpp>
#include <fstream>

class City : public GameObject {
	
	std::vector<int> dw;
	float relig; // ���� � ���������
	std::vector<float> murd; // (��� �����������, ��� ��������) ��� ��������

public:
	virtual void render(sf::RenderTarget& r) override;

	virtual void update() override;

	std::vector<int> dwellers();
	
	float faith();

	std::vector<float> kill();

	void save(std::ofstream fout);
};