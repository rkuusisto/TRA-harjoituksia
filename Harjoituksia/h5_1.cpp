#include "stdafx.h"
#include "h5_1.h"
#include <iostream>

using namespace std;

void h5_1_1(unsigned long n)
{

	for(unsigned long i = 0; i < n; i++)
	{
		cout << fibonacci(i) << endl;
	}
}


void h5_1_2(int a, int b)
{

	cout << syt(a, b) << endl;

}

int syt(int a, int b)
{
	return b == 0 ? a : syt(b, a%b);
}

unsigned long fibonacci(unsigned long n)
{

	return n <= 1 ? n : fibonacci(n - 1) + fibonacci(n - 2);
	

}
