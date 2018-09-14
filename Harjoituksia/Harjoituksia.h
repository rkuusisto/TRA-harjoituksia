#pragma once
#include <string>
#include <vector>
#include "Henkilo.h"

class Alkio;
void pause();
int get_int(int min, std::string prompt);
std::string get_string(std::string prompt);
void print_table(std::vector<Henkilo> table);
void print_at(Alkio *lista, int at);
void add_after(Alkio* lista, int after);
void remove_at(Alkio **lista, int at);
void printll(Alkio *lista);