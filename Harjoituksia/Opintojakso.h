#pragma once
#include <string>
#include <boost/algorithm/string/replace.hpp>

class Opintojakso
{
public:
	Opintojakso();

	Opintojakso(const std::string& opinto, const std::string& tyyppi, const std::string& toteutus,
		const std::string& alkupvm, const std::string& loppupvm, const std::string& nimi,
		const std::string& vastuutoimipiste, const std::string& vastuuohjelma);


	std::string get_opinto() const;
	void get_opinto(const std::string& opinto);
	std::string get_tyyppi() const;
	void get_tyyppi(const std::string& tyyppi);
	std::string get_toteutus() const;
	void get_toteutus(const std::string& toteutus);
	std::string get_alkupvm() const;
	void get_alkupvm(const std::string& alkupvm);
	std::string get_loppupvm() const;
	void get_loppupvm(const std::string& loppupvm);
	std::string get_nimi() const;
	void get_nimi(const std::string& nimi);
	std::string get_vastuutoimipiste() const;
	void get_vastuutoimipiste(const std::string& vastuutoimipiste);
	std::string get_vastuuohjelma() const;
	void get_vastuuohjelma(const std::string& vastuuohjelma);

	void print();

	static int cmpfunc(const void *a, const void *b);

	~Opintojakso();

private:
	std::string opinto,
	            tyyppi,
	            toteutus,
	            alkupvm,
	            loppupvm,
	            nimi,
	            vastuutoimipiste,
	            vastuuohjelma;
};

inline
std::ostream &operator<<(std::ostream &os, Opintojakso const &oj)
{
	std::string nimi = oj.get_nimi();

	std::replace(nimi.begin(), nimi.end(), 'ä', 'a');
	std::replace(nimi.begin(), nimi.end(), 'ö', 'o');
	std::replace(nimi.begin(), nimi.end(), 'Ä', 'A');
	std::replace(nimi.begin(), nimi.end(), 'Ö', 'O');

	

	return os << oj.get_opinto() << "\t" << (oj.get_opinto().length() < 8 ? "\t" : "") << nimi.c_str();
}




inline bool operator<(const Opintojakso &l, const Opintojakso &r)
{

	return l.get_opinto() < r.get_opinto();
}

inline bool operator==(const Opintojakso &l, const Opintojakso &r)
{

	return l.get_opinto() < r.get_opinto();
}

inline bool operator>(const Opintojakso &l, const Opintojakso &r)
{

	return l.get_opinto() < r.get_opinto();
}

inline bool operator<=(const Opintojakso &l, const Opintojakso &r)
{
	
	return l.get_opinto() < r.get_opinto();
}

inline bool operator>=(const Opintojakso &l, const Opintojakso &r)
{

	return l.get_opinto() < r.get_opinto();
}