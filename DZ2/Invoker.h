#pragma once

#include "Command.h"

class Invoker
{
	Command* pCommand;

public:
	~Invoker()
	{
		delete pCommand;
	}

	void DeleteDynamicObj(DynamicObject* pObj, std::vector<DynamicObject*>& pVec);


};
