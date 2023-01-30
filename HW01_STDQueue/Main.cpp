#include "Queue.h"

int main(void)
{
	//Initialize Queue
	Queue<int> myQueue;

	//Push elements
	myQueue.Push(3);
	myQueue.Push(2);
	//Print queue
	myQueue.Print();
	//pop an element
	myQueue.Pop();
	//add elements
	myQueue.Push(17);
	//Print queue
	myQueue.Print();
	
	
	//AlbertoClass test
	Queue<AlbertoClass> myAlbertoQueue;
	AlbertoClass test;
	AlbertoClass demo(19);
	AlbertoClass pilot(44);

	std::cout << "Alberto Tests:" << std::endl;
	myAlbertoQueue.Push(test);
	myAlbertoQueue.Push(demo);
	myAlbertoQueue.Print();
	myAlbertoQueue.Pop();
	myAlbertoQueue.Push(pilot);
	myAlbertoQueue.Print();


	std::cout << "Press Enter to finish." << std::endl;


	
	getchar();

}