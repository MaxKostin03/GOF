#pragma once

#include <vector>
#include <memory>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"


using namespace std;

class SBomber
{
public:

    SBomber();
   
    bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:

    vector<shared_ptr<DynamicObject>> vecDynamicObj;
    vector<shared_ptr<GameObject>> vecStaticObj;

    bool exitFlag;

    uint64_t startTime;
    uint64_t finishTime;
    uint64_t passedTime;
    uint16_t bombsNumber;
    uint16_t deltaTime;
    uint16_t fps;
    int16_t score;
    uint64_t stateTime;

    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(std::shared_ptr<Bomb> pBomb);

    void __fastcall DeleteDynamicObj(std::shared_ptr<DynamicObject> pBomb);
    void __fastcall DeleteStaticObj(std::shared_ptr<GameObject> pObj);

    shared_ptr<Ground> FindGround() const;
    shared_ptr<Plane> FindPlane() const;
    shared_ptr<LevelGUI> FindLevelGUI() const;
    vector<shared_ptr<DestroyableGroundObject>> FindDestoyableGroundObjects() const;
    vector<shared_ptr<Bomb>> FindAllBombs() const;

    void DropBomb();
};