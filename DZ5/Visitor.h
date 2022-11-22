#pragma once

class Bomb;
class Plane;

class Visitor
{
public:
	virtual void logging(const Bomb& bomb) const = 0;
	virtual void logging(const Plane& plane) const = 0;

};

class LoggingVisitor : public Visitor
{
public:
	void logging(const Bomb& bomb) const override;
	void logging(const Plane& plane) const override;

};