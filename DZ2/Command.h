#pragma once
#include"SBomber.h"

class Command
{
public:
	virtual ~Command() {}
	virtual void execute() = 0;
};

class DeleteDynamicObjCommand : public Command
{
private:
	DynamicObject* pObj;
	std::vector<DynamicObject*>& pVec;
public:
	DeleteDynamicObjCommand(DynamicObject* _pObj, std::vector<DynamicObject*>& _pVec) :pObj(_pObj), pVec(_pVec) {}
	void execute() override;

};

class DeleteStaticObjCommand : public Command
{
private:
	GameObject* pObj;
	std::vector<GameObject*>& pVec;

public:
	DeleteStaticObjCommand(GameObject* _pObj, std::vector<GameObject*>& _pVec) : pObj(_pObj), pVec(_pVec) {}
	void execute() override;
};

class DropBombCommand : public Command
{
private:
	Plane* const pPlane;
	std::vector<DynamicObject*>& pVec;
	int16_t& score;
	uint16_t& bombsNumber;

public:
	DropBombCommand(Plane* const obj, std::vector<DynamicObject*>& _pVec, uint16_t& _bombsNumber, int16_t& _score) :pPlane(obj),
		pVec(_pVec), bombsNumber(_bombsNumber), score(_score) {}
	void execute() override;

};

class DropTheBombCommand : public Command
{
private:
	Plane* const pPlane;
	std::vector<DynamicObject*>& pVec;
	int16_t& score;
	uint16_t& bombsNumber;

public:
	DropTheBombCommand(Plane* const obj, std::vector<DynamicObject*>& _pVec, uint16_t& _bombsNumber, int16_t& _score) :pPlane(obj),
		pVec(_pVec), bombsNumber(_bombsNumber), score(_score) {}
	void execute() override;

};