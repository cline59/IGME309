#pragma once
#ifndef __QUEUE_H_
#define __QUEUE_H_
#include <iostream>
#include <deque>
#include "Alberto.h"
#define uint unsigned int

template <class T>
class Queue {
	public:
		//Not sure if I got the Rule of three right. It was based on code from a few of the DSA1 examples.
		//I can confirm that VS is detecting memory leaks

		//constructor
		Queue() {
			maxQueueSize = 1;
			currentQueueSize = 0;
			queueArray = new T[maxQueueSize];
			queueArray[1] = {};
		}
		//copy constructor
		Queue(const Queue<T>& other) :
			queueArray (new char[std::strlen(other.queueArray) + 1]) 
		{
			strcpy_s(queueArray, maxQueueSize, other.queueArray);
			maxQueueSize = other.maxQueueSize;
			currentQueueSize = other.currentQueueSize;

		}
		//copy assignmet operator
		Queue& operator=(const Queue<T>& other)
		{
			if (this != &other)
			{
				Queue temp(other);
				Swap(temp);
			}
			return *this;
		}
		//deconstructor
		~Queue() {
			delete[] queueArray;
		}
		
		friend void Print(Queue<T> other)
		{
			other.Print();
		}
		//Add item to end of queue
		void Push(T input) {
			//checks if array is full
			if (GetSize() == maxQueueSize) {
				SetArray(); //doubles if yes
			}

			currentQueueSize++;
			queueArray[currentQueueSize] = input;

			//Sort queue from lowest to highest
			int temp;

			for (int i = 0; i < currentQueueSize; i++) {
				for (int j = i + 1; j < currentQueueSize; j++)
				{
					if (queueArray[j] < queueArray[i]) {
						temp = queueArray[i];
						queueArray[i] = queueArray[j];
						queueArray[j] = temp;
					}
				}
			}
		}
		//remove item from start of queue
		void Pop() {
			T tempArray[currentQueueSize - 1] = {};
			for (int i = 2; i <= currentQueueSize; i++) {
				tempArray[i - 1] = queueArray[i];
			}

			currentQueueSize--;
			queueArray = new T[maxQueueSize];
			queueArray = {};

			for (int i = 1; i <= currentQueueSize; i++) {
				queueArray[i] = tempArray[i];
			}
		}
		//print contents of queue
		void Print(void) const
		{
			std::cout << "Queue:" << std::endl;
			for (int i = 1; i <= currentQueueSize; i++) {
				std::cout << queueArray[i] << std::endl;
			}
		}
	private:
		T* queueArray;
		int maxQueueSize;
		int currentQueueSize;

		void Swap(Queue<T>& other) {
			std::swap(queueArray, other.queueArray);
		}

		//double size of array
		void SetArray() {
			//creates temp array to hold queue for transfer
			T tempArray[currentQueueSize] = {};
			for (int i = 1; i <= currentQueueSize; i++) {
				tempArray[i] = queueArray[i]; //this line is causing an error, saying that "array type 'T [this->8]' is not assignable"
			}

			//double the size of the array
			maxQueueSize = maxQueueSize * 2;
			queueArray = new T[maxQueueSize];
			queueArray = {};

			//reassign the items in the queue
			for (int i = 1; i <= currentQueueSize; i++) {
				queueArray[i] = tempArray[i];
			}

		}
		//returns num of items in que
		int GetSize() {
			return currentQueueSize;
		}

		//checks if queueArray is empty
		bool IsEmpty() {
			if (queueArray == {0}) {
				return true;
			}
			return false;
		}
		//void Release(void);
		//void Init(void);
};

#endif //__QUEUE_H_