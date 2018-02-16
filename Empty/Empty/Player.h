#pragma once

#include <TxCoord.h>
#include "Object.h"

class Resource;

class Player : public Object
{
private:
	Resource* rc;

public:
	Player();
	~Player();

	void Update(float _delta_time);
};