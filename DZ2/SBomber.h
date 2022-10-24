#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class Command;

class SBomber
{
public:

    SBomber();
    ~SBomber();

    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:
    Command* pCommand;
    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    std::vector<DynamicObject*> pVec;

    bool exitFlag;
    bool nBombFlag;

    uint64_t startTime;
    uint64_t finishTime;
    uint64_t passedTime;
    uint16_t bombsNumber;
    uint16_t deltaTime;
    uint16_t fps;
    int16_t score;

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();

    void CheckDestoyableObjects(Bomb* pBomb);

    void DeleteDynamicObj(DynamicObject* pBomb);
    void DeleteStaticObj(GameObject* pObj);

    Ground* FindGround() const;
    Plane* FindPlane() const;
    LevelGUI* FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();
    void DropTheBomb();
};