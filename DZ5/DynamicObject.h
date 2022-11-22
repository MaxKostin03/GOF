#pragma once

#include <stdint.h>

#include "GameObject.h"
#include "Visitor.h"

class DynamicObject : public GameObject
{
public:

    DynamicObject() : speed(0.0), xDirection(0.0), yDirection(0) { }

    inline void SetSpeed(double sp) { speed = sp; }
    inline void SetDirection(double dx, double dy) { xDirection = dx; yDirection = dy; }

    virtual void Move(uint16_t time) { x += xDirection * speed * time * 0.001; y += yDirection * speed * time * 0.001; };

    double GetSpeed() const
    {
        return speed;
    }

    double getXdirection() const
    {
        return xDirection;
    }

    double getYdirection() const
    {
        return yDirection;
    }

    virtual void Accept(const Visitor& visitor) = 0;

protected:

    double speed;
    double xDirection, yDirection;
};