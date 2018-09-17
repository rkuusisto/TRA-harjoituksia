#pragma once
#include <string>

////////////////////////////////////////////////////////////////////////////////////////////
//Kuvaus : Bin‰‰ripuuhun liittyv‰t luokkam‰‰ritykset
//Tiedosto: bpuu.h
//Tekij‰ : http://www.cprogramming.com/tutorial/lesson18.html
//Pva: : 15.1.2015


using namespace std;
//solmun esittely
template <class T>
class node {
public:
	T value; //alkion sis‰lt‰m‰ tieto
	class node<T> *left; //vasen alipuu
	class node<T> *right; //oikea alipuu
};
//bin‰‰ripuun esittely
template <class T>
class btree
{
public:
	btree(); //muodostin
	~btree(); //hajoitin
	void print_preorder(); //tulostaa puun preorder-j‰rjestyksess‰
	void print_inorder();
	void print_postorder();
	void insert(T value); //lis‰‰ solmun
	node<T> *search(T value); //etsii solmun
	void destroy_tree(); //tuhoaa puun
	void print_tree(); //testi‰ varten
private:
	void destroy_tree(node<T> *leaf);
	void insert(T value, node<T> *leaf);
	node<T> *search(T value, node<T> *leaf);
	void print_preorder(node<T> *leaf);
	void print_inorder(node<T> *leaf);
	void print_postorder(node<T> *leaf);
	void print_tree(node<T> *, int);

	node<T> *root; //tieto juurisolmusta
};

template <typename T>
btree<T>::btree() //Muodostin
{
	root = NULL;
}

template <typename T>
btree<T>::~btree() //Hajoitin
{
	destroy_tree();
}
//Juurisolmun tuhoaminen

template <typename T>
void btree<T>::destroy_tree()
{
	destroy_tree(root);
}
//Muun solmun tuhoaminen

template <typename T>
void btree<T>::destroy_tree(node<T> *leaf)
{
	if (leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
//Solmun lis‰ys v‰liin. Huomioi tapauksen, jossa juurisolmua ei viel‰ ole.
//K‰ytt‰j‰ kutsuu t‰t‰ aina, t‰m‰ kutsuu tarvittaessa yksityist‰
//ylikuormitettua insert(metodia)

template <typename T>
void btree<T>::insert(T key)
{
	if (root != NULL)
		insert(key, root);
	else
	{
		root = new node<T>;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
	}
}

//Solmun lis‰ys v‰liin, t‰t‰ kutsuu vain julkinen insert() metodi

template <typename T>
void btree<T>::insert(T key, node<T> *leaf)
{
	if (key < leaf->value)
	{
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else
		{
			leaf->left = new node<T>;
			leaf->left->value = key;
			leaf->left->left = NULL; //Sets the left child of the child node to null
			leaf->left->right = NULL; //Sets the right child of the child node to null
		}
	}
	else if (key >= leaf->value)
	{
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else
		{
			leaf->right = new node<T>;
			leaf->right->value = key;
			leaf->right->left = NULL; //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
}

template <typename T>
node<T> *btree<T>::search(T key, node<T> *leaf)
{
	if (leaf != NULL)
	{
		if (key == leaf->value)
			return leaf;
		if (key<leaf->value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

template <typename T>
node<T> *btree<T>::search(T key)
{
	return search(key, root);
}
//Tulostus esij‰rjestyksess‰ (preorder)
//Julkinen metodi, l‰htee juurisolmusta

template <typename T>
void btree<T>::print_preorder() {
	print_preorder(root);
	cout << " \n";
}
//rekursiolla kutsuttava yksityinen versio

template <typename T>
void btree<T>::print_preorder(node<T> *t) {
	if (t != NULL) {
		cout << t->value << endl;
		print_preorder(t->left);
		print_preorder(t->right);
	}
}


//Tulostus esij‰rjestyksess‰ (inorder)
//Julkinen metodi, l‰htee juurisolmusta

template <typename T>
void btree<T>::print_inorder() {
	print_inorder(root);
	cout << " \n";
}
//rekursiolla kutsuttava yksityinen versio

template <typename T>
void btree<T>::print_inorder(node<T> *t) {
	if (t != NULL) {
		print_inorder(t->left);
		cout << t->value << endl;
		print_inorder(t->right);
	}
}


//Tulostus esij‰rjestyksess‰ (postorder)
//Julkinen metodi, l‰htee juurisolmusta

template <typename T>
void btree<T>::print_postorder() {
	print_postorder(root);
	cout << " \n";
}
//rekursiolla kutsuttava yksityinen versio

template <typename T>
void btree<T>::print_postorder(node<T> *t) {
	if (t != NULL) {
		print_postorder(t->left);
		print_postorder(t->right);
		cout << t->value << endl;
	}
}



template <typename T>
void btree<T>::print_tree() {
	print_tree(root, -1);
}
//T‰m‰ on testi‰ varten, tulostaa puun vaakatasoon
//L‰hde: Nummelin 1995, s. 44 - 45

template <typename T>
void btree<T>::print_tree(node<T> *nod, int n) {
	int i;
	if (nod) {
		print_tree(nod->right, ++n);
		for (i = 0; i<5 * n; i++) putchar(' ');
		printf("-->%s%2d\n", (nod->value).c_str(), n + 1);
		print_tree(nod->left, n);
	}
}