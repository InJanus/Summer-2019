#include <iostream>
#include "..\\Lab_8\pqueue\pqueue.h"
//#include "..\\Lab_8\heap\heap.h"
#include <string>
#include <cstdlib>
#include <chrono>

int main()
{
	typedef std::chrono::high_resolution_clock Clock;
	bool flag = true;
	int listOfSizes[5] = { 500, 1000, 2000, 5000, 20000 };
	int k = 0;
	PQueue myqueue;
	heap myheap;
	while (flag)
	{
		//cout << "Choose the amount of items to be in the pQueue" << endl;
		int maxNum;
		//cin >> maxNum;

		maxNum = listOfSizes[k];
		auto start1 = Clock::now();
		for (int i = 0; i < maxNum; i++)
		{
			myqueue.insert(rand());
		}
		auto end1 = Clock::now();

		std::cout << "Queue Insert, Size " <<  maxNum << ": "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count()
			<< " nanoseconds" << std::endl;

		auto start2 = Clock::now();
		for (int i = 0; i < maxNum; i++)
		{
			myheap.insert(rand());
		}
		auto end2 = Clock::now();

		std::cout << "Heap insert, Size " << maxNum << ": "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2).count()
			<< " nanoseconds" << std::endl;

		auto start3 = Clock::now();
		for (int j = maxNum; j > 0; j--)
		{
			myqueue.remove();
		}
		auto end3 = Clock::now();
		std::cout << "Queue Remove, Size " << maxNum << ": "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(end3 - start3).count()
			<< " nanoseconds" << std::endl;

		auto start4 = Clock::now();
		for (int j = maxNum; j > 0; j--)
		{
			myheap.remove();
		}
		auto end4 = Clock::now();
		std::cout << "Heap Remove, Size " << maxNum << ": "
			<< std::chrono::duration_cast<std::chrono::nanoseconds>(end4 - start4).count()
			<< " nanoseconds" << std::endl;

		k++;

		if (k == 5)
		{
			flag = false;
		}
	}
	

	return 0;
}
