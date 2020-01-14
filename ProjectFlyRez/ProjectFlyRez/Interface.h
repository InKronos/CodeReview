#pragma once
#include "stdafx.h"

class Interface
{
private:
	//TODO lista stringów z danymi na podstawie których maj¹ wyœwietlaæ siê dane;
	std::string loadScreen;
public:
	void getLoadScreenFromFile(std::string fileName);
	void showLoadScreen();

};

