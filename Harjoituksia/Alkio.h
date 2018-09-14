#pragma once
class Alkio
{
public:
	
	Alkio() = default;
	int luku;
	Alkio *seuraava;
	Alkio *get(int at);
	void remove_at(Alkio** lista, int at);

	~Alkio();
};

