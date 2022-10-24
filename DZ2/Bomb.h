#pragma once

#include "DynamicObject.h"

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10; // стоимость бомбы в очках

	void Draw() const override;

};

class BombDecorator : public DynamicObject
{
	Bomb bomb;

public:
	void Move(uint16_t time)override;
	void Draw() const override;
	void SetDirection(double dx, double dy)override;
	void SetSpeed(double sp)override;
	void SetPos(double nx, double ny)override;
	void SetWidth(uint16_t widthN)override;
};