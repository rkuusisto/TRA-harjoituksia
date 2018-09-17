#include <iostream>

using namespace std;

#pragma once
template <class T>
class Alkio
{
public:

	Alkio() = default;
	Alkio(T luku);
	T arvo;

	Alkio* seuraava;
	Alkio* get(int at);

	void add(T *alkio);

	Alkio<T>* get_last();
	
	static void add(Alkio** lista, Alkio* alkio, int at);
	static void remove_at(Alkio** lista, int at);

	int index_of(Alkio* alkio);

	void print_all();
	~Alkio();
};

template <typename T>
Alkio<T>* Alkio<T>::get(int at)
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


template <class T>
Alkio<T>* Alkio<T>::get_last()
{
	Alkio<T>* kohdistin = this;

	while(kohdistin->seuraava != nullptr)
	{
		kohdistin = kohdistin->seuraava;
	}

	return kohdistin;
}


template <typename T>
void Alkio<T>::add(T *t)
{
	Alkio<T> *kohdistin = nullptr;
	if(this == nullptr)
	{
		 kohdistin = new Alkio<T>(*t);
	} else
	{
		kohdistin = this->get_last();
		kohdistin->seuraava = new Alkio<T>(*t);
	}

	
	
}

template <typename T>
void Alkio<T>::add(Alkio** lista, Alkio* alkio, int at)
{
	Alkio* indeksi = *lista;
	Alkio* edellinen = indeksi;


	if (at == 0)
	{
		alkio->seuraava = indeksi;
		*lista = alkio;
	}
	else
	{
		for (int i = 0; i < at; i++)
		{
			edellinen = indeksi;
			indeksi = indeksi->seuraava;
		}

		alkio->seuraava = indeksi;
		edellinen->seuraava = alkio;
	}
}

template <typename T>
void Alkio<T>::remove_at(Alkio<T>** lista, int at)
{
	Alkio<T>* indeksi = *lista;
	if(indeksi == nullptr)
	{
		cout << "Lista on tyhjä" << endl;
		return;
	}
	Alkio<T>* edellinen = indeksi;
	Alkio<T>* seuraava = indeksi->seuraava;

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

		//cout << "Asetetaan kohtaan " << at << " seuraava " << seuraava->arvo << endl;
		edellinen->seuraava = seuraava;

		delete indeksi;
	}
}


template <class T>
int Alkio<T>::index_of(Alkio<T>* alkio)
{
	Alkio<T>* kohdistin = this;
	int i = 0;
	while (true)
	{
		if (alkio == kohdistin)
		{
			return i;
		}
		if (kohdistin->seuraava != nullptr)
		{
			kohdistin = kohdistin->seuraava;
		}
		else
		{
			break;
		}
		i++;
	}
	return -1;
}


template <typename T>
void Alkio<T>::print_all()
{
	Alkio<T>* indeksi = this; //Osoitetaan listan alkuun

	if (indeksi == nullptr)
	{
		cout << "Lista on tyhjä";
	}

	//Tulostetaan lista
	cout << endl;
	int i = 0;


	while (indeksi != NULL)
	{
		i++;
		cout << i << '\t' << indeksi->arvo << endl;
		indeksi = indeksi->seuraava; //osoitetaan seuraavaa alkiota
	}
}

template <typename T>
Alkio<T>::Alkio(T luku)
{
	this->arvo = luku;
}


template <typename T>
Alkio<T>::~Alkio<T>()
{
}
