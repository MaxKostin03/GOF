#pragma once

#include "LevelGUI.h"
#include <string>
#include <queue>

class Mediator 
{
public:
	
	virtual ~Mediator() {}

	void addToQueue(std::string message) 
	{
		gui->messageQueue.push(message);
	}

private:

	LevelGUI* gui;

};