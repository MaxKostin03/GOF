#pragma once

#include <vector>
#include "PIMPL.h"

class SBomberImpl;

class SBomber
{
public:

    SBomber();
    ~SBomber();

    inline bool GetExitFlag() const { return pimpl->exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    SBomberImpl* pimpl;

};