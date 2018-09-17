#pragma once

#include <iostream>
#include <tuple>

using namespace std;

class Henkilo

{
public:
	Henkilo();
	Henkilo(string nimi, string puhelin);
	void print();

	char* c_str() const;

	string nimi;
	string puhelinnumero;


	

	~Henkilo();
};


inline
std::ostream &operator<<(std::ostream &os, const Henkilo &h)
{
	return os << h.nimi.c_str() << '\t' << h.puhelinnumero.c_str();
}

inline bool operator<(const Henkilo &l, const Henkilo &r)
{
	//return std::tie(l.nimi, l.puhelinnumero) < std::tie(r.nimi, r.puhelinnumero);
	return l.c_str() < r.c_str();
}


inline bool operator>=(const Henkilo &l, const Henkilo &r)
{
	return std::tie(l.nimi, l.puhelinnumero) < std::tie(r.nimi, r.puhelinnumero);
}