#pragma once
#include <string>
#include <vector>
#include "Henkilo.h"
#include "Alkio.h"

void pause();
int get_int(int min, std::string prompt);
std::string get_string(std::string prompt);
void print_table(std::vector<Henkilo> table);

template<typename T>
void print_at(Alkio<T> *lista, int at);

bool not_null(Alkio<Henkilo> *kohdistin);
void trim_option(string& opt);