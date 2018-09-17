#pragma once
#include <iostream>

using namespace std;

void swap(int* a, int* b);
void bubbleSort(int a[], int N);
void selectionSort(int a[], int N);

int bubbleSort_main();

template <typename T>
void tulosta(int koko, T* taulu);

void tulosta_aika(long alku, long loppu);

void merge(int a[], int L, int M, int R);

template <typename T>
void mergeSort(T a[], int L, int R);

void quickSort(int arr[], int left, int right);
int cmpfunc(const void* a, const void* b);

void libQsort(int arr[], int left, int right);

void do_sort(int koko, int* taulu, long& alku, long& loppu, const char* otsikko, void (*action)(int*, int, int));

template <typename T>
void mergeSort(T a[], int L, int R)
{
	if (L < R)
	{
		int M = (L + R) / 2; // haetaan taulukon keskikohta, Vaihe 1
		mergeSort(a, L, M); // järjestetään osataulut rekursiivisesti, Vaihe 2
		mergeSort(a, M + 1, R);
		merge(a, L, M, R); // lomitetaan osataulut takaisin suuruusjärjestykseen
	}
}

template <typename T>
void merge(T a[], int L, int M, int R)
{
	int i, j, k;
	int n1 = M - L + 1;
	int n2 = R - M;

	/* Luodaan tilapäiset taulukot. Huom! Pitäisi oikeastaan testata, että muistia on eikä */
	/* generoidu poikkeusta */
	T* Left = new T[n1];
	T* Right = new T[n2];

	/* Kopioidaan data tilapäisiin taulukoihin Left[] ja Right[] */
	for (i = 0; i < n1; i++)
		Left[i] = a[L + i];
	for (j = 0; j < n2; j++)
		Right[j] = a[M + 1 + j];

	/* Lomitetaan tilapäiset taulukot takaisin alkuperäiseen a[L..R]*/
	i = 0;
	j = 0;
	k = L;
	while (i < n1 && j < n2)
	{
		if (Left[i] <= Right[j])
		{
			a[k] = Left[i];
			i++;
		}
		else
		{
			a[k] = Right[j];
			j++;
		}
		k++;
	}

	/* Kopioidaan Left[]:n jäljellejääneet alkiot, jos niitä on */
	while (i < n1)
	{
		a[k] = Left[i];
		i++;
		k++;
	}

	/* Kopioidaan Right[]:n jäljellejääneet alkiot, jos niitä on */
	while (j < n2)
	{
		a[k] = Right[j];
		j++;
		k++;
	}
	//Vapautetaan dynaaminen muistinvaraus
	delete[]Left;
	Left = NULL;
	delete[]Right;
	Right = NULL;
}


template <typename T>
void tulosta(int koko, T* taulu)
{
	for (int i = 0; i < koko; i++)
		cout << taulu[i] << endl;
}
