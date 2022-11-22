#pragma once

#include "DynamicObject.h"
#include <vector>

class DestroyableGroundObject;

class Bomb : public DynamicObject
{
public:

	static const uint16_t BombCost = 10;

	void Draw() const override;

	void Accept(const Visitor& visitor) override;

	DestroyableGroundObject* CheckDestroyableObjects();

	void addObservers(DestroyableGroundObject* obj);

private:
	std::vector<DestroyableGroundObject*> observerVec;
};
