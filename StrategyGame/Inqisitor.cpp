#include "Inqisitor.h"
#include "WorldController.h"
#include "MoveOrder.h"
#include "WorldRenderer.h"
#include "GameObject.h"

class WorldController;

void Inqisitor::render(sf::RenderTarget& r)
{

}

void Inqisitor::update()
{

}

void Inqisitor::save(std::ofstream & fout)
{
	std::string name = "Inqisitor";
	this->save_me(fout, name);
}