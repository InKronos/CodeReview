#pragma once
#include "stdafx.h"

class Interface
{
private:
	//TODO lista string�w z danymi na podstawie kt�rych maj� wy�wietla� si� dane;
	std::string loadScreen;
public:
	void getLoadScreenFromFile(std::string fileName);
	void showLoadScreen();

};

