#pragma once
#include <memory>
#include "GameObject.h"
class Order {
	std::shared_ptr<GameObject> subj;
public :
	virtual std::shared_ptr<GameObject> subject() = 0;
	virtual bool finished() = 0;
};