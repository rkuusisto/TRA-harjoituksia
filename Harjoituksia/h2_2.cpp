#include "stdafx.h"
#include "h2_2.h"
#include "Alkio.h"
#include <string>
#include "Henkilo.h"
#include "Harjoituksia.h"

using namespace std;




int h2_2_3()
{
	cout << "HENKILÖIDEN/PUH.NUMEROIDEN KÄSITTELY";

	string opt;
	Alkio<Henkilo>** lista = new Alkio<Henkilo>*();
	Alkio<Henkilo>* kohdistin = *lista;

	/* DEFAULT TEST DATASET */

	*lista = new Alkio<Henkilo>(*new Henkilo("Riku", "123"));
	kohdistin = *lista;
	kohdistin->add(new Henkilo("Matti", "456"));
	kohdistin->add(new Henkilo("Maija", "789"));

	/* DEFAULT TEST DATASET DONE*/

	while (true)
	{
		tulosta_valikko();

		cin >> opt;

		trim_option(opt);

		if (opt == "a")
		{
			lisaa_henkilo(lista);
		}
		else if (opt == "b")
		{
			if (not_null(*lista)) continue;
			nayta_ensimmainen(*lista);
			kohdistin = *lista;
		}
		else if (opt == "c")
		{
			if (not_null(kohdistin)) continue;
			
			kohdistin = kohdistin->seuraava;

			if (kohdistin == nullptr)
			{
				cout << endl << "Aloitetaan alusta..." << endl;
				kohdistin = *lista;
			}

			nauta_seuraava(kohdistin);
		}
		else if (opt == "d")
		{
			poista_henkilo(lista, kohdistin);
			kohdistin = *lista;
		}
		else if (opt == "e")
		{
			tulosta_kaikki(*lista);
		}
		else if (opt == "0")
		{
			break;
		}
	}

	return 0;
}


void tulosta_valikko()
{
	cout << endl;
	cout << endl;
	tulosta_valikkorivi("a.", "Lisaa uusi henkilo");
	tulosta_valikkorivi("b.", "Nayta ensimmainen henkilo");
	tulosta_valikkorivi("c.", "Nayta seuraava henkilo");
	tulosta_valikkorivi("d.", "Poista kohdalla oleva henkilo");
	tulosta_valikkorivi("e.", "Tulosta kaikki tietueet");
	tulosta_valikkorivi("0)", "Lopetus");
}

void tulosta_valikkorivi(string tunnus, string selite)
{
	cout << tunnus << " " << selite << endl;
}

void lisaa_henkilo(Alkio<Henkilo>** lista)
{
	string nimi = get_string("nimi: ");
	string puhelinnumero = get_string("puhelinnumero: ");
	Henkilo* h = new Henkilo();

	h->nimi = nimi;
	h->puhelinnumero = puhelinnumero;

	if (*lista == nullptr)
	{
		*lista = new Alkio<Henkilo>(*h);
	}
	else
	{
		Alkio<Henkilo>* kohdistin = *lista;
		kohdistin->add(h);
	}
}

void nayta_ensimmainen(Alkio<Henkilo>* lista)
{
	cout << lista->arvo;
}

void nauta_seuraava(Alkio<Henkilo>* kohdistin)
{
	cout << kohdistin->arvo;
}

void poista_henkilo(Alkio<Henkilo>** lista, Alkio<Henkilo>* kohdistin)
{
	Alkio<Henkilo>* l = *lista;

	int at = l->index_of(kohdistin);
	Alkio<Henkilo>::remove_at(lista, at);
}

void tulosta_kaikki(Alkio<Henkilo>* lista)
{
	lista->print_all();
}


int h2_2_2()
{
	auto* lista = new Alkio<string>();
	auto* indeksi = lista;


	int kpl = 7;

	for (int i = 0; i < kpl; i++)
	{
		indeksi->arvo = "kek" + to_string(i);
		if (kpl - i > 1)
		{
			indeksi->seuraava = new Alkio<string>();
			indeksi = indeksi->seuraava;
		}
		indeksi->seuraava = nullptr;
	}

	lista->print_all();

	Alkio<string>::remove_at(&lista, 0);
	Alkio<string>::add(&lista, new Alkio<string>("kek"), 0);
	Alkio<string>::add(&lista, new Alkio<string>("kek"), 6);

	lista->print_all();

	return 0;
}

