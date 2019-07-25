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
		using namespace std;
		heap h;
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
				h.insert(inval);
			}
			else if (option == 2) {
				int outval;
				h.remove();
				h.printHeap();
			}
			else if (option == 3) {
				h.printHeap();
			}
			else {
				inner_flag = false;
			}
		}
	}
	else if (task == 3) {

		typedef std::chrono::high_resolution_clock Clock;
		bool flag = true;
		int listOfSizes[5] = { 500, 1000, 2000, 5000, 20000 };
		int k = 0;
		auto start = Clock::now();
		auto end = Clock::now();

		srand(time(0));
		
		while (flag)
		{
			PQueue myqueue;
			heap myheap; 
			//cout << "Choose the amount of items to be in the pQueue" << endl;
			int maxNum;
			int r;
			//cin >> maxNum;
			maxNum = listOfSizes[k];
			/* auto start1*/ start= Clock::now();
			for (int i = 0; i < maxNum; i++){
				r = (rand()%maxNum);
				myqueue.insert(r);
			}
			
			/* auto end1*/ end = Clock::now();
			std::cout << "Queue Insert, Size " << maxNum << ": "
				<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
				<< " nanoseconds" << std::endl;


			/* auto start2*/start = Clock::now();
			for (int i = 0; i < maxNum; i++){
				r = (rand()%maxNum);
				myheap.insert(r);
			}
			/* auto end2*/ end= Clock::now();
			std::cout << "Heap insert, Size " << maxNum << ": "
				<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
				<< " nanoseconds" << std::endl;


			/* auto start3*/ start= Clock::now();
			for (int j = maxNum-1; j > 0; j--){
				myqueue.remove();
			}
			/* auto end3*/ end= Clock::now();
			std::cout << "Queue Remove, Size " << maxNum << ": "
				<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
				<< " nanoseconds" << std::endl;


			/* auto start4*/ start= Clock::now();
			for (int j = maxNum-1; j > 0; j--){
				myheap.remove();
			}
			/* auto end4*/ end= Clock::now();
			std::cout << "Heap Remove, Size " << maxNum << ": "
				<< std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
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
