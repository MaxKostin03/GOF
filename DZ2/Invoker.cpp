#include"Invoker.h"

void Invoker::DeleteDynamicObj(DynamicObject* pObj, std::vector<DynamicObject*>& pVec)
{
	pCommand = new DeleteDynamicObjCommand(pObj, pVec);
	pCommand->execute();
}