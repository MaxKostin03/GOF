
#include <conio.h>
#include <windows.h>

#include "MyTools.h"
#include "SBomber.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"
#include "House.h"
#include "FileLogger.h"


using namespace std;
using namespace MyTools;
extern FileLogger g_logger;

SBomber::SBomber() : pimpl(new SBomberImpl)
{
    g_logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    Plane* p = new Plane;
    p->SetDirection(1, 0.1);
    p->SetSpeed(4);
    p->SetPos(5, 10);
    pimpl->vecDynamicObj.push_back(p);

    LevelGUI* pGUI = new LevelGUI;
    pGUI->SetParam(pimpl->passedTime, pimpl->fps, pimpl->bombsNumber, pimpl->score);
    const uint16_t maxX = GetMaxX();
    const uint16_t maxY = GetMaxY();
    const uint16_t offset = 3;
    const uint16_t width = maxX - 7;
    pGUI->SetPos(offset, offset);
    pGUI->SetWidth(width);
    pGUI->SetHeight(maxY - 4);
    pGUI->SetFinishX(offset + width - 4);
    pimpl->vecStaticObj.push_back(pGUI);

    Ground* pGr = new Ground;
    const uint16_t groundY = maxY - 5;
    pGr->SetPos(offset + 1, groundY);
    pGr->SetWidth(width - 2);
    pimpl->vecStaticObj.push_back(pGr);

    Tank* pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(30, groundY - 1);
    pimpl->vecStaticObj.push_back(pTank);

    pTank = new Tank;
    pTank->SetWidth(13);
    pTank->SetPos(50, groundY - 1);
    pimpl->vecStaticObj.push_back(pTank);

    House* pHouse = new House;
    pHouse->SetWidth(13);
    pHouse->SetPos(80, groundY - 1);
    pimpl->vecStaticObj.push_back(pHouse);
}

SBomber::~SBomber()
{
    for (size_t i = 0; i < pimpl->vecDynamicObj.size(); i++)
    {
        if (pimpl->vecDynamicObj[i] != nullptr)
        {
            delete pimpl->vecDynamicObj[i];
        }
    }

    for (size_t i = 0; i < pimpl->vecStaticObj.size(); i++)
    {
        if (pimpl->vecStaticObj[i] != nullptr)
        {
            delete pimpl->vecStaticObj[i];
        }
    }
}

void SBomber::MoveObjects()
{
    g_logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < pimpl->vecDynamicObj.size(); i++)
    {
        if (pimpl->vecDynamicObj[i] != nullptr)
        {
            pimpl->vecDynamicObj[i]->Move(pimpl->deltaTime);
        }
    }
};

void SBomber::CheckObjects()
{
    g_logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    pimpl->CheckPlaneAndLevelGUI();
    pimpl->CheckBombsAndGround();
};

void SBomber::ProcessKBHit()
{
    int c = _getch();

    if (c == 224)
    {
        c = _getch();
    }

    g_logger.WriteToLog(string(__FUNCTION__) + " was invoked. key = ", c);

    switch (c) {

    case 27: // esc
        pimpl->exitFlag = true;
        break;

    case 72: // up
        pimpl->FindPlane()->ChangePlaneY(-0.25);
        break;

    case 80: // down
        pimpl->FindPlane()->ChangePlaneY(0.25);
        break;

    case 'b':
        pimpl->DropBomb();
        break;

    case 'B':
        pimpl->DropBomb();
        break;

    default:
        break;
    }
}

void SBomber::DrawFrame()
{
    g_logger.WriteToLog(string(__FUNCTION__) + " was invoked");

    for (size_t i = 0; i < pimpl->vecDynamicObj.size(); i++)
    {
        if (pimpl->vecDynamicObj[i] != nullptr)
        {
            pimpl->vecDynamicObj[i]->Draw();
        }
    }

    for (size_t i = 0; i < pimpl->vecStaticObj.size(); i++)
    {
        if (pimpl->vecStaticObj[i] != nullptr)
        {
            pimpl->vecStaticObj[i]->Draw();
        }
    }

    GotoXY(0, 0);
    pimpl->fps++;

    pimpl->FindLevelGUI()->SetParam(pimpl->passedTime, pimpl->fps, pimpl->bombsNumber, pimpl->score);
}

void SBomber::TimeStart()
{
    g_logger.WriteToLog(string(__FUNCTION__) + " was invoked");
    pimpl->startTime = GetTickCount64();
}

void SBomber::TimeFinish()
{
    pimpl->finishTime = GetTickCount64();
    pimpl->deltaTime = uint16_t(pimpl->finishTime - pimpl->startTime);
    pimpl->passedTime += pimpl->deltaTime;

    g_logger.WriteToLog(string(__FUNCTION__) + " deltaTime = ", (int)pimpl->deltaTime);
}