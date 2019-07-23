#include <iostream>
#include "..\\Lab_8\pqueue\pqueue.h"
#include "..\\Lab_8\heap\heap.h"
#include <string>
#include <cstdlib>
#include <chrono>

int main()
{
	int task;
	std::cout << "task 1, 2 or 3?" << endl;
	std::cin >> task;
	if (task == 1) {
		//run tASK 1
		using namespace std;
		PQueue q;
		int option;
		bool inner_flag = true;
		while (inner_flag) {
			cout << "1)Insert\n2)Remove\n3)Print\n4)End" << endl;
			cin >> option;
			//switch (option)
			if (option == 1) {
				int inval;
				cout << "Enter Value to insert: " << endl;
				cin >> inval;
				q.insert(inval);
			}
			else if (option == 2) {
				int outval;
				outval = q.remove();
				cout << "Removed: " << outval << endl;
			}
			else if (option == 3) {
				q.printQueue();
			}
			else {
				inner_flag = false;
			}
		}
	}
	else if (task == 2) {
		heap h;
		h.insert(2);
		h.insert(3);
		h.printHeap();
		h.remove();
		h.printHeap();

	}
	else if (task == 3) {

		typedef std::chrono::high_resolution_clock Clock;
		bool flag = true;
		int listOfSizes[5] = { 500, 1000, 2000, 5000, 20000 };
		int k = 0;
		PQueue myqueue;
		//heap myheap; //FIXME
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

			std::cout << "Queue Insert, Size " << maxNum << ": "
				<< std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1).count()
				<< " nanoseconds" << std::endl;

			auto start2 = Clock::now();
			for (int i = 0; i < maxNum; i++)
			{
				//myheap.insert(rand());
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
				//myheap.remove();
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

	}
	return 0;
}
