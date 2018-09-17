#include "stdafx.h"
#include "Opintojakso.h"
#include <iostream>

using namespace std;

Opintojakso::Opintojakso()
{
}


Opintojakso::Opintojakso(const std::string& opinto, const std::string& tyyppi, const std::string& toteutus,
	const std::string& alkupvm, const std::string& loppupvm, const std::string& nimi,
	const std::string& vastuutoimipiste, const std::string& vastuuohjelma)
	: opinto(opinto),
	tyyppi(tyyppi),
	toteutus(toteutus),
	alkupvm(alkupvm),
	loppupvm(loppupvm),
	nimi(nimi),
	vastuutoimipiste(vastuutoimipiste),
	vastuuohjelma(vastuuohjelma)
{
}

std::string Opintojakso::get_opinto() const
{
	return opinto;
}

void Opintojakso::get_opinto(const std::string& opinto)
{
	this->opinto = opinto;
}

std::string Opintojakso::get_tyyppi() const
{
	return tyyppi;
}

void Opintojakso::get_tyyppi(const std::string& tyyppi)
{
	this->tyyppi = tyyppi;
}

std::string Opintojakso::get_toteutus() const
{
	return toteutus;
}

void Opintojakso::get_toteutus(const std::string& toteutus)
{
	this->toteutus = toteutus;
}

std::string Opintojakso::get_alkupvm() const
{
	return alkupvm;
}

void Opintojakso::get_alkupvm(const std::string& alkupvm)
{
	this->alkupvm = alkupvm;
}

std::string Opintojakso::get_loppupvm() const
{
	return loppupvm;
}

void Opintojakso::get_loppupvm(const std::string& loppupvm)
{
	this->loppupvm = loppupvm;
}

std::string Opintojakso::get_nimi() const
{
	return nimi;
}

void Opintojakso::get_nimi(const std::string& nimi)
{
	this->nimi = nimi;
}

std::string Opintojakso::get_vastuutoimipiste() const
{
	return vastuutoimipiste;
}

void Opintojakso::get_vastuutoimipiste(const std::string& vastuutoimipiste)
{
	this->vastuutoimipiste = vastuutoimipiste;
}

std::string Opintojakso::get_vastuuohjelma() const
{
	return vastuuohjelma;
}

void Opintojakso::get_vastuuohjelma(const std::string& vastuuohjelma)
{
	this->vastuuohjelma = vastuuohjelma;
}

Opintojakso::~Opintojakso()
{
}


void Opintojakso::print()
{
	cout << "Opinto:\t\t\t" << opinto << endl;
	cout << "Tyyppi:\t\t\t" << tyyppi << endl;
	cout << "Toteutus:\t\t" << toteutus << endl;
	cout << "Alkupvm:\t\t" << alkupvm << endl;
	cout << "Loppupvm:\t\t" << loppupvm << endl;
	cout << "Nimi:\t\t\t" << nimi << endl;
	cout << "Vastuutoimipiste:\t" << vastuutoimipiste << endl;
	cout << "Vastuuohjelma:\t\t" << vastuuohjelma << endl;
}

int Opintojakso::cmpfunc(const void *a, const void *b)
{
	if (*(Opintojakso*)a < *(Opintojakso*)b) return -1;
	if (*(Opintojakso*)a == *(Opintojakso*)b) return 0;
	if (*(Opintojakso*)a > *(Opintojakso*)b) return 1;
	return 0;
}
