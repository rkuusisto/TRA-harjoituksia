#include "stdafx.h"
#include "Alkio.h"
#include <iostream>

using namespace std;


Alkio *Alkio::get(int at)
{
	Alkio* indeksi = this;

	for (int i = 0; i < at; i++)
	{
		if (indeksi->seuraava != nullptr)
		{
			indeksi = indeksi->seuraava;
		}
		else
		{
			cout << "IndexOutOfBounds " << i << ":" << i - 1 << endl;
			return nullptr;
		}
	}
	return indeksi;
}

void remove_at(Alkio** lista, int at)
{
	Alkio* indeksi = *lista;
	Alkio* edellinen = indeksi;
	Alkio* seuraava = indeksi->seuraava;

	if (at == 0)
	{
		*lista = seuraava;
		delete indeksi;
	}
	else
	{
		for (int i = 0; i < at; i++)
		{
			edellinen = indeksi;

			if (indeksi->seuraava != nullptr)
			{
				indeksi = indeksi->seuraava;
			}
			else
			{
				cout << endl << "IndexOutOfBounds " << at << " > " << i << endl;
				return;
			}
			seuraava = indeksi->seuraava;
		}

		//cout << "Asetetaan kohtaan " << at << " seuraava " << seuraava->luku << endl;
		edellinen->seuraava = seuraava;

		cout << "Indeksi: " << indeksi->luku << endl;
		delete indeksi;
	}
}


Alkio::~Alkio()
{
}
