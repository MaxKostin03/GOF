#pragma once

#include "DynamicObject.h"
#include "Bomb.h"
#include <vector>
#include <iostream>

class BombIterator
{
public:

	BombIterator(const std::vector<DynamicObject*>& vecDynamicObject) :
		_vecDynamicObject(vecDynamicObject),
		_index(-1),
		_ptr(nullptr)
	{
		++(*this);
	}

	void reset()
	{
		_index = -1;
		_ptr = nullptr;
	}

	BombIterator& operator++()
	{
		_index++;

		if (_index == -1)
		{
			_index = 0;
		}

		for (; _index < _vecDynamicObject.size(); ++_index)
		{
			Bomb* pBomb = dynamic_cast<Bomb*>(_vecDynamicObject[_index]);
			if (pBomb != nullptr)
			{
				_ptr = pBomb;
				break;
			}
		}

		if (_index == _vecDynamicObject.size())
		{
			_index = -1;
			_ptr = nullptr;
		}

		return *this;
	}

	Bomb*& operator*()
	{
		Bomb* bomb = dynamic_cast<Bomb*>(_vecDynamicObject[_index]);
		if (bomb != nullptr)
		{
			return bomb;
		}
	}

	bool operator == (const BombIterator& iter) const
	{
		if (_index == iter._index && _ptr == iter._ptr && _vecDynamicObject == iter._vecDynamicObject)
		{
			return true;
		}
		return false;
	}

	bool operator != (const BombIterator& iter) const
	{
		return !(*this == iter);
	}

	BombIterator begin()
	{
		BombIterator iter(_vecDynamicObject);
		return iter;
	}

	BombIterator end()
	{
		BombIterator iter(_vecDynamicObject);
		iter.reset();
		return iter;
	}

	void print()
	{
		Bomb* bomb = dynamic_cast<Bomb*>(_vecDynamicObject[_index]);
		if (bomb != nullptr)
			std::cout << "print=" << bomb->GetY() << std::endl;
	}

private:
	const std::vector<DynamicObject*>& _vecDynamicObject;
	int _index;
	DynamicObject* _ptr;
};