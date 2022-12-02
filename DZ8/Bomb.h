#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:
	static const uint16_t BombCost = 10; 
	Bomb() {};
	Bomb(const Bomb& pBomb);
	Bomb* clone() override;
	void Draw() const override;

private:

};