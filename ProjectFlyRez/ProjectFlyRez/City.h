#pragma once
#include "TableBase.h"
#include "stdafx.h"


class City :
	public TableBase
{
	std::string name;
public:
	City(int _id, std::string _name);
};

