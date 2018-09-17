#pragma once
#include <iostream>
#include "Henkilo.h"
#include "Alkio.h"

using namespace std;

int h2_2_2();
int h2_2_3();

void tulosta_valikko();
void tulosta_valikkorivi(string tunnus, string selite);


void lisaa_henkilo(Alkio<Henkilo> **lista);

void nayta_ensimmainen(Alkio<Henkilo> *lista);

void nauta_seuraava(Alkio<Henkilo> *kohdistin);

void poista_henkilo(Alkio<Henkilo> **lista, Alkio<Henkilo> *kohdistin);

void tulosta_kaikki(Alkio<Henkilo> *lista);

