#pragma once
#include <memory>
#include "GameObject.h"
#include "Actors.h"

class Actors;
class Order {
	std::shared_ptr<Actors> subj;
public :
	virtual std::shared_ptr<Actors> subject() = 0;
	virtual bool finished() = 0;
};