#include "stdafx.h"
#include "Sort.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void bubbleSort2(int a[], int N)
{
	bool swapped = true;

	int i = N - 1;
	while (swapped)
	{
		swapped = false;
		for (int j = 1; j <= i; j++)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				swapped = true;
			}
		}
		i--;
	}
}

void bubbleSort(int a[], int N)
{
	
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
			
			}
		}
	}
}

void selectionSort(int a[], int N)
{
	int i, j, min;

	for (i = 0; i < N - 1; i++)
	{
		min = i;
		for (j = i + 1; j < N; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
	}
}




void quickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
			while (arr[j] > pivot)
				j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

void do_sort(int koko, int* taulu, long& alku, long& loppu, const char* otsikko, void (*action)(int*, int, int))
{
	cout << endl << otsikko << endl << endl;

	tulosta(koko, taulu);


	cout << endl;

	alku = clock();
	action(taulu, 0, koko-1);
	loppu = clock();

	tulosta(koko, taulu);

	cout << endl;

	tulosta_aika(alku, loppu);
}

int bubbleSort_main()
{
	int koko;
	int* taulu;
	int* taulu2;
	int* taulu3;

	cout << "Ohjelma kysyy taulukon koon, arpoo sen t‰yteen \n";
	cout << "satunnaislukuja ja j‰rjest‰‰ sen \n\n";
	cout << " - anna taulukon koko : ";
	cin >> koko;
	taulu = new int[koko];
	taulu2 = new int[koko];
	taulu3 = new int[koko];
	//alustetaan generaattori
	srand((unsigned)time(NULL));
	//tehd‰‰n satunnaislukutaulukko
	for (int i = 0; i < koko; i++)
	{
		taulu[i] = rand();
		taulu2[i] = taulu[i];
		taulu3[i] = taulu[i];
		
	}

	long alku, loppu;



	//do_sort(koko, taulu, alku, loppu, "Merge sort", mergeSort);
	do_sort(koko, taulu2, alku, loppu, "Quick sort", quickSort);
	do_sort(koko, taulu, alku, loppu, "Library qsort", libQsort);




	return 0;
}

void libQsort(int arr[], int left, int right)
{
	qsort(arr, right-left+1, sizeof(int), cmpfunc);
}


int cmpfunc(const void * a, const void * b)
{
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a == *(int*)b) return 0;
	if (*(int*)a > *(int*)b) return 1;
	return 0;
}

void tulosta_aika(long alku, long loppu)
{
	cout << endl;
	cout << "Aikaa kului " << (loppu - alku) << " CPU-ticksi‰ eli "
		<< (((double)loppu - alku) / CLOCKS_PER_SEC) << " sec\n";
}



void swap(int* a, int* b)
{
	int temp = *a;
	a = b;
	b = &temp;
}
