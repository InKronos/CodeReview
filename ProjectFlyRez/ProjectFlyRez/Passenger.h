#pragma once
#include "TableBase.h"
#include "stdafx.h"
class Passenger :
	public TableBase
{
	std::string name;
	std::string surname;
	std::string password;
};

