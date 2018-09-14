#include "stdafx.h"
#include "Henkilo.h"


Henkilo::Henkilo()
{
	nimi = "";
	puhelinnumero = "";
}

Henkilo::Henkilo(const string nimi, const string puhelin)
{
	this->nimi = nimi;
	this->puhelinnumero = puhelin;
}


void Henkilo::set_nimi(string nimi)
{
	this->nimi = nimi;
}

void Henkilo::set_puhelinnumero(string numero)
{
	this->puhelinnumero = numero;
}

void Henkilo::print()
{
	cout << nimi.c_str() << '\t' << puhelinnumero.c_str() << '\n';
}


Henkilo::~Henkilo()
{
}
