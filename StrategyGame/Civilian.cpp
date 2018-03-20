#include "Civilian.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"
#include <fstream>
#include <iostream>
using namespace std;

class WorldController;

void Civilian::render(sf::RenderTarget& r)
{

}

void Civilian::update()
{

}

void Civilian::save_me(std::ofstream fout)
{
	fout << "Civilian" << '\t';
	fout << this->position().x + ' ' + this->position().y << '\t';
	fout << this->loc_position().x + ' ' + this->loc_position().y << '\t';
	fout << this->health() << '\t' << this->faith() << '\t';
	fout << this->get_power() << '\n';
}

