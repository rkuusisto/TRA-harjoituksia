#pragma once

#include <iostream>
#include "Printable.h"

using namespace std;

class Henkilo

{
public:
	Henkilo();
	Henkilo(string nimi, string puhelin);
	void set_nimi(string nimi);
	void set_puhelinnumero(string numero);
	void print();

	~Henkilo();
private:
	string nimi;
	string puhelinnumero;
};

