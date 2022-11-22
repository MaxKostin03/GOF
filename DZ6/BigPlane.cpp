#include "BigPlane.h"
#include "MyTools.h"
#include <iostream>

using namespace MyTools;

void BigPlane::DrawBody() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x, y);
    std::cout << "=========>>";
    GotoXY(x, y + 1);
    std::cout << "===========>>";
}

void BigPlane::DrawWings() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\\\\\";
    GotoXY(x + 3, y + 2);
    std::cout << "////////";
}

void BigPlane::DrawTail() const
{
    MyTools::SetColor(CC_LightBlue);
    GotoXY(x - 2, y - 1);
    std::cout << "===";
}
