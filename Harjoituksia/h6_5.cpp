#include "stdafx.h"
#include "h6_5.h"
#include "CSVReader.h"
#include <iostream>
#include "Opintojakso.h"
#include "Sort.h"
#include "Harjoituksia.h"

using namespace std;


int compare(const void* a, const void* b)
{
	string _a = (*(string*)a);
	string _b = (*(Opintojakso*)b).get_opinto();

	return _a < _b ? -1 : _a > _b;
}


void do_find(Opintojakso* dataset, unsigned int count,
             void* (*action)(void const*, void const*, unsigned int*, unsigned int,
                             _CoreCrtNonSecureSearchSortCompareFunction))
{
	string str = get_string("Opintojakso: ");

	cout << endl;

	Opintojakso* o = (Opintojakso*)action(&str, dataset, &count, sizeof(Opintojakso), compare);

	if (o == nullptr)
	{
		cout << "Opintojaksoa " << str << " ei loydy";
		return;
	}

	o->print();
}

void* bsearch2(
	void const* _Key,
	void const* _Base,
	unsigned int* _NumOfElements,
	unsigned int _SizeOfElements,
	_CoreCrtNonSecureSearchSortCompareFunction _CompareFunction
)
{
	return bsearch(_Key, _Base, (size_t)*_NumOfElements, _SizeOfElements, _CompareFunction);
}

void h6_5_5()
{
	// Creating an object of CSVWriter
	CSVReader reader("C:\\Temp\\Opintojaksot.csv", ";");

	vector<vector<string>> dataList = reader.getData();

	unsigned int oj_count = dataList.size();

	Opintojakso* oj_lista = new Opintojakso[oj_count];
	int top = -1;


	for (vector<string> row : dataList)
	{
		top++;
		if (top > 0)
		{
			Opintojakso* oj = new Opintojakso(row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
			oj_lista[top] = *oj;
		}
	}


	long alku, loppu;

	cout << endl;

	alku = clock();
	do_find(oj_lista, oj_count, _lfind);
	loppu = clock();

	tulosta_aika(alku, loppu);

	cout << endl;

	alku = clock();
	mergeSort(oj_lista, 0, top);
	do_find(oj_lista, oj_count, bsearch2);
	loppu = clock();

	cout << endl;

	tulosta_aika(alku, loppu);

	cout << endl;
}
