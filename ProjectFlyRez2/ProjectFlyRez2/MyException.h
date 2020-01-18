#pragma once
#include "stdafx.h"
class MyException :
	public std::exception
{
	const char* func;
	const char* info;
public:
	MyException(const char* msg, const char* func_, const char* info_ = "") : std::exception(msg),
		func(func_),
		info(info_)
	{
	}

	const char* get_func() const { return func; }
	const char* get_info() const { return info; }


};

