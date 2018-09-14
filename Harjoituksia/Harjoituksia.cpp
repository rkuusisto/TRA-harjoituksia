// Harjoituksia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Harjoituksia.h"
#include <iostream>
#include <sstream>
#include "Henkilo.h"
#include <vector>
#include "Alkio.h"

using namespace std;

const int X_MAX = 2;
const int Y_MAX = 3;

int main()
{
	Alkio* lista;
	Alkio* indeksi;

	lista = new Alkio();

	indeksi = lista;

	int i, kpl;

	kpl = 7; //get_int(1, "Listan koko: ");

	for (int ii = 0; ii < kpl; ii++)
	{
		indeksi->luku = 10 + ii;
		if (kpl - ii > 1)
		{
			indeksi->seuraava = new Alkio();
			indeksi = indeksi->seuraava;
		}
		indeksi->seuraava = nullptr;
	}

	remove_at(&lista, 0);

	printll(lista);

	pause();

	return 0;
}

void add_after(Alkio* lista, int after)
{
	Alkio* indeksi = lista->get(after);
	Alkio* edellinen = indeksi;
	Alkio* seuraava = indeksi->seuraava;

	

}





void print_at(Alkio* lista, int at)
{
	Alkio* indeksi = lista->get(at);
	cout << indeksi->luku << endl;
}

void printll(Alkio* lista)
{
	Alkio* indeksi;
	//Tulostetaan lista
	cout << endl;
	int i = 0;
	indeksi = lista; //Osoitetaan listan alkuun
	do
	{
		cout << "Listan " << i++ << ":s alkio on " << indeksi->luku << endl;
		indeksi = indeksi->seuraava; //osoitetaan seuraavaa alkiota
	}
	while (indeksi->seuraava != NULL);
}

void print_table(vector<Henkilo> table)
{
	for (int i = 0; i < table.size(); i++)
	{
		table.at(i).print();
	}
}

string get_string(const string prompt)
{
	string ret_str;
	std::cout << prompt;
	std::getline(cin, ret_str);
	return ret_str;
}

int get_int(const int min, const std::string prompt)
{
	int ret_integer;
	std::string str_number;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, str_number); //get string input
		std::stringstream convert(str_number); //turns the string into a stream

		//checks for complete conversion to integer and checks for minimum value
		if (convert >> ret_integer && !(convert >> str_number) && ret_integer >= min) return ret_integer;

		std::cin.clear(); //just in case an error occurs with cin (eof(), etc)
		std::cerr << "Input must be >= " << min << ". Please try again.\n";
	}
}


void pause()
{
	system("PAUSE");
}
