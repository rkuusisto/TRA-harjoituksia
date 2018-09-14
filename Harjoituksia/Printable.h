#pragma once
#include <iostream>

class Printable
{
public:
	virtual ~Printable() = default;
	virtual void print()
	{
		std::cout << "default print";
	};
	
	Printable();

};


