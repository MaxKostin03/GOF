
#include <iostream>

#include "House.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

House::House()
{
	for (size_t i = 0; i < MyHouseHight; ++i)
	{
		for (size_t j = 0; j < MyHouseWidth; ++j)
		{
			look[i][j] = ' ';
		}
	}
}

bool House::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void House::Draw() const
{
	MyTools::SetColor(CC_Yellow);
	for (size_t i = 0; i < MyHouseHight; ++i)
	{
		GotoXY(x, y - i);
		for (size_t j = 0; j < MyHouseWidth; ++j)
		{
			cout << this->look[MyHouseHight - i - 1][j];
		}
	}
}

void MyHouseBuilderA::buildMyWalls(House& myHouse)
{
	for (size_t i = 2; i < myHouse.getHight() - 1; ++i)
	{
		myHouse.look[i][1] = '#';
		myHouse.look[i][myHouse.getWidth() - 6] = '#';
	}
}

void MyHouseBuilderA::buildMyDoors(House& myHouse)
{
	for (size_t i = 6; i < myHouse.getHight() - 1; ++i)
	{
		myHouse.look[i][3] = '#';
	}
}

void MyHouseBuilderA::buildMyWindow(House& myHouse)
{
	for (size_t i = 4; i < 6; ++i)
	{
		myHouse.look[i][5] = '#';
		myHouse.look[i][6] = '#';
	}
}

void MyHouseBuilderA::buildMyRoof(House& myHouse)
{
	for (size_t i = 1; i < 10; ++i)
	{
		myHouse.look[0][i] = '#';
	}
	for (size_t i = 0; i < 11; ++i)
	{
		myHouse.look[1][i] = '#';
	}
}

void MyHouseBuilderA::buildMyPipe(House& myHouse)
{
	for (size_t i = 1; i < MyHouseWidth; ++i)
	{
		{
			if (i > 7 && i < 10)
			{
				myHouse.look[0][i] = '#';
				continue;
			}
		}
		myHouse.look[0][i] = ' ';
	}
}