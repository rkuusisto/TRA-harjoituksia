#include "stdafx.h"
#include "Queue.h"
#include <iostream>

using namespace std;

void h2_4_4()
{
	Queue<int>* queue = new Queue<int>(10);

	queue->enqueue(10);
	queue->enqueue(20);
	queue->enqueue(30);
	queue->enqueue(40);
	queue->enqueue(50);
	queue->enqueue(60);
	queue->enqueue(70);
	queue->enqueue(80);
	queue->enqueue(90);
	queue->enqueue(100);
	queue->enqueue(110);
	queue->enqueue(120);
	queue->enqueue(130);
	queue->enqueue(140);
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;
	cout << queue->dequeue() << endl;

}
