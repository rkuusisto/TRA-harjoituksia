#include "stdafx.h"
#include "h3_2_1.h"
#include "bpuu.h"
#include <iostream>
#include <fstream>
#include "Henkilo.h"
#include <ctime>

void h3_2_1_1() {
	btree<string> oma_puu;
	string kysy;
	char s[100];
	int pit;
	//Kysyt‰‰n puuhun liittyv‰t tiedot k‰ytt‰j‰lt‰ ja t‰ytet‰‰n puu
	do {
		cout << "Anna data : ";
		gets_s(s);
		pit = strnlen(s, 99);
		if (pit > 0) {
			kysy = s;
			oma_puu.insert(kysy);
		}
	} while (pit > 0);
	//Tulostetaan puu vaakasuorassa
	oma_puu.print_tree();
	cout << endl;
	//Tulostetaan sen sis‰ltˆ preorder-j‰rjestyksess‰
	oma_puu.print_preorder();
	oma_puu.print_inorder();
	oma_puu.print_postorder();
	cout << endl;
}

void h3_2_1_2(string path)
{

	btree<string> puu;
	
	ifstream file (path);
	if(file.is_open())
	{
		string line;
		while(getline(file, line))
		{
			//cout << line << endl;
			puu.insert(line);
		}
		puu.print_tree();
		cout << endl;
		puu.print_preorder();
		puu.print_inorder();
		puu.print_postorder();
		cout << endl;
	}
	else cout << "Ei pyge...";

	file.close();


}

void h3_2_1_3(string path)
{

	srand((unsigned)time(NULL));

	btree<Henkilo> puu;

	ifstream file(path);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
		{
			//cout << line << endl;
			int r = 450000000 + (int) (10000000.0 * (rand() / (RAND_MAX + 1.0)));
			Henkilo *h = new Henkilo(line, "+358" + to_string(r));
			
			puu.insert(*h);
		}
		puu.print_tree();
		cout << endl;
		puu.print_preorder();
		puu.print_inorder();
		puu.print_postorder();
		cout << endl;
	}
	else cout << "Ei pyge...";

	file.close();


}