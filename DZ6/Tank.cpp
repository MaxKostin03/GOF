
#include <iostream>

#include "Tank.h"
#include "MyTools.h"

using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
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

void Tank::Draw() const
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";
}

std::vector<std::string>Tank::messages
{
	"This is not Russia, you need to dig deeper.",
	"Hey Man! Nice Shot!",
	"Son, you're in the army now!",
	"The dead know only one thing: it is better to be alive.",
	"Don't sh*t me, man!",
	"Were you born a fat, slimy, scumbag puke pieca' sh*t Private Pyle, or did you have to work on it?"
};

void Tank::addToQueue() {
	_mediator->addToQueue(messages[Roll(0,5)]);
}