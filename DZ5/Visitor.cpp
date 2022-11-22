#include "Visitor.h"
#include "MyTools.h"
#include "Bomb.h"
#include "Plane.h"

#include <string>

void LoggingVisitor::logging(const Bomb& bomb) const
{

	std::string str = "";
	str += "Bomb: speed=";
	str += std::to_string(bomb.GetSpeed());
	str += " x=";
	str += std::to_string(bomb.getXdirection());
	str += " y=";
	str += std::to_string(bomb.getYdirection());

	MyTools::WriteToLog(str);
}

void LoggingVisitor::logging(const Plane& plane) const
{
	std::string str = "";
	str += "Plane: speed=";
	str += std::to_string(plane.GetSpeed());
	str += " x=";
	str += std::to_string(plane.getXdirection());
	str += " y=";
	str += std::to_string(plane.getYdirection());

	MyTools::WriteToLog(str);
}