#pragma once

#include "TankAdaptee.h"
#include "DestroyableGroundObject.h"

class TankAdapter : public DestroyableGroundObject {
public:
    TankAdapter() {}
    ~TankAdapter() {}

    bool __fastcall isInside(double x1, double x2) const override
    {
        return tankAdaptee.isInRange(x1, x2);
    }

    inline uint16_t GetScore() const override
    {
        return tankAdaptee.GetScore();
    }

    void Draw() const override
    {
        tankAdaptee.Paint();
    }

    void SetPos(double nx, double ny)
    {
        tankAdaptee.SetPos(nx, ny);
    }

    double GetY() const 
    {
        return tankAdaptee.GetY();
    }

    double GetX() const 
    {
        return tankAdaptee.GetX();
    }

    void SetWidth(uint16_t widthN) 
    {
        tankAdaptee.SetWidth(widthN);
    }

    uint16_t GetWidth() const 
    {
        return tankAdaptee.GetWidth();
    }
    
private:
    TankAdaptee tankAdaptee;
};
