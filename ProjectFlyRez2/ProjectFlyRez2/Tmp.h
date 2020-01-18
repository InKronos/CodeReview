#pragma once
#include "stdafx.h"


class Tmp
{
protected:
	int id;
public:
	virtual void print() {};
	int getId() {
		return this->id;
	}
};
