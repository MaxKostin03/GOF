#pragma once

#include <stdint.h>

#include "DestroyableGroundObject.h"

constexpr size_t MyHouseHight = 7;
constexpr size_t MyHouseWidth = 14;

class House : public DestroyableGroundObject
{
public:
	House();

	friend class MyHouseBuilderA;

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	size_t getHight()
	{
		return MyHouseHight;
	}

	size_t getWidth()
	{
		return MyHouseWidth;
	}

private:
	char look[MyHouseHight][MyHouseWidth];
	const uint16_t score = 40;
};

class MyHouseBuilder
{
public:
	virtual ~MyHouseBuilder() = default;
	virtual void buildMyWalls(House& myHouse) {};
	virtual void buildMyDoors(House& myHouse) {};
	virtual void buildMyRoof(House& myHouse) {};
	virtual void buildMyPipe(House& myHouse) {};
	virtual void buildMyWindow(House& myHouse) {};
};

class MyHouseBuilderA : public MyHouseBuilder
{
public:
	void buildMyWalls(House& myHouse) override;
	void buildMyDoors(House& myHouse) override;
	void buildMyRoof(House& myHouse) override;
	void buildMyPipe(House& myHouse) override;
	void buildMyWindow(House& myHouse) override;
};

class Director
{
public:
	static void createMyHouse(MyHouseBuilder& builder, House& myHouse)
	{
		builder.buildMyWalls(myHouse);
		builder.buildMyDoors(myHouse);
		builder.buildMyRoof(myHouse);
		builder.buildMyPipe(myHouse);
		builder.buildMyWindow(myHouse);
	}
};