#include"Command.h"

void DeleteDynamicObjCommand::execute()
{
	auto it = pVec.begin();
	for (; it != pVec.end(); it++)
	{
		if (*it == pObj)
		{
			pVec.erase(it);
			break;
		}
	}
}

void DeleteStaticObjCommand::execute()
{
	auto it = pVec.begin();
	for (; it != pVec.end(); it++)
	{
		if (*it == pObj)
		{
			pVec.erase(it);
			break;
		}
	}
}

void DropBombCommand::execute()
{
	double x = pPlane->GetX() + 4;
	double y = pPlane->GetY() + 2;

	Bomb* pBomb = new Bomb;
	pBomb->SetDirection(0.3, 1);
	pBomb->SetSpeed(2);
	pBomb->SetPos(x, y);
	pBomb->SetWidth(SMALL_CRATER_SIZE);

	pVec.push_back(pBomb);

	bombsNumber--;
	score -= Bomb::BombCost;

}

void DropTheBombCommand::execute()
{
	double x = pPlane->GetX() + 4;
	double y = pPlane->GetY() + 2;

	BombDecorator* pBomb = new BombDecorator;
	pBomb->SetDirection(0.3, 1);
	pBomb->SetSpeed(2);
	pBomb->SetPos(x, y);
	pBomb->SetWidth(SMALL_CRATER_SIZE);

	pVec.push_back(pBomb);

	bombsNumber--;
	score -= Bomb::BombCost;

}