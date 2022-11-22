#include "ColorPlane.h"
#include "MyTools.h"
#include <iostream>

using namespace MyTools;

ConsoleColor color = (ConsoleColor)Roll(0, 15);

void ColorPlane::DrawBody() const
{
    MyTools::SetColor(color);
    GotoXY(x, y);
    std::cout << "=========>";
}

void ColorPlane::DrawWings() const
{
    MyTools::SetColor(color);
    GotoXY(x + 3, y - 1);
    std::cout << "\\\\\\\\";
    GotoXY(x + 3, y + 1);
    std::cout << "////";
}

void ColorPlane::DrawTail() const
{
    MyTools::SetColor(color);
    GotoXY(x - 2, y - 1);
    std::cout << "===";
}
