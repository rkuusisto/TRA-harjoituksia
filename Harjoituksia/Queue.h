#pragma once

#include <iostream>

using namespace std;


template <class T>
class Queue
{
public:
	Queue<T>(int size);

	void enqueue(T const &v);
	T dequeue();

	void insert(T const &v);
	T min();
	T max();
	T extract_min();
	T extract_max();
	void decrease_key(T const &x, int k);
	void increase_key(T const &x, int k);


	~Queue<T>();

private:
	int end;
	int start;
	int size;
	T * queue;
};

template<class T>
inline void Queue<T>::enqueue(T const & v)
{
	queue[end++%size] = v;
}

template<class T>
inline T Queue<T>::dequeue()
{
	int i = start++%size;
	T v = queue[i];
	cout << "NULL: " << (v == NULL) << endl;
	queue[i] = NULL;
	return v;
}

template<typename T>
Queue<T>::Queue(int size)
{
	this->size = size;
	this->queue = new T[size];
}


template<typename T>
Queue<T>::~Queue()
{
	delete [] queue;
}
