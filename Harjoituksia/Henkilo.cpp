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

void Henkilo::print()
{
	cout << c_str() << endl;
}


Henkilo::~Henkilo()
{
}



char* Henkilo::c_str() const
{

	size_t len = strlen(nimi.c_str()) + strlen(puhelinnumero.c_str());

	char* str = new char[len + 1];

	int n_length = nimi.length();

	for(int ptr = 0; ptr < n_length; ptr++)
	{
		str[ptr] = nimi[ptr];
	}

	for(int ptr = 0; ptr < puhelinnumero.length(); ptr++)
	{
		str[ptr + n_length] = puhelinnumero[ptr];
	}

	str[len] = '\0';

	return str;

}
