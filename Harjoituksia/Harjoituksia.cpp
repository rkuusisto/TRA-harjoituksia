// Harjoituksia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Harjoituksia.h"
#include <iostream>
#include <sstream>
#include "Henkilo.h"
#include <vector>
#include "Alkio.h"
#include "h2_4.h"
#include "h3_2_1.h"
#include "h5_1.h"
#include "h2_2.h"
#include "Sort.h"
#include "h6_5.h"

using namespace std;

const int X_MAX = 2;
const int Y_MAX = 3;


int main()
{
	//h2_2_2();
	//h2_2_3();
	//h2_4_4();
	//h3_2_1_1();
	//h3_2_1_2("C:\\Temp\\test.txt");
	//h3_2_1_3("C:\\Temp\\test.txt");
	//h5_1_1(30);
	//h5_1_2(345, 165);

	//bubbleSort_main(); //h6_5_4

	h6_5_5();


	pause();
	return 0;
}





template <typename T>
void print_at(Alkio<T>* lista, int at)
{
	Alkio<T>* indeksi = lista->get(at);
	cout << indeksi->arvo << endl;
}


void print_table(vector<Henkilo> table)
{
	for (unsigned int i = 0; i < table.size(); i++)
	{
		table.at(i).print();
	}
}

string get_string(const string prompt)
{
	string ret_str;
	cout << prompt;
	cin >> ret_str;
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

void trim_option(string& opt)
{
	if (opt.length() > 1)
	{
		opt = opt.substr(0, 1);
	}
}

bool not_null(Alkio<Henkilo>* kohdistin)
{
	if (kohdistin == nullptr)
	{
		cout << endl << "Lista on tyhjä" << endl;
	}
	return kohdistin == nullptr;
}

void pause()
{
	system("PAUSE");
}
