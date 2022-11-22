#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"
#include "Mediator.h"

#include <vector>
#include <string>

class Tank : public DestroyableGroundObject
{
public:

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	Tank(Mediator* mediator) : _mediator(mediator) {}

	void addToQueue();

private:

	const uint16_t score = 30;

	Mediator* _mediator;

	static std::vector<std::string> messages;
};