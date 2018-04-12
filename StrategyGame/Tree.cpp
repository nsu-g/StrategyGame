#include "Tree.h"

class Tree;
void Tree::render(sf::RenderTarget& r)
{

}

void Tree::update()
{

}

void Tree::save(std::ofstream & fout)
{
	std::string name = "Tree";
	this->save_me(fout, name);
}