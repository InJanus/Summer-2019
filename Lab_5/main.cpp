//main
#include <iostream>
#include ".\\sort\sort.h"
using namespace std;
#include <stdio.h>       
#include <stdlib.h>     
#include <time.h>       
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;



int main(){
    // int size = 0;
    // int num;
    // srand(time(0));
    // cout << "Size of array: \n 1) 10 \n 2) 100 \n 3) 500 \n 4)5000 \n 5)25000 \n 6) 100000 " <<endl;
    // cin >> num;
    // switch(num){
    //     case 1: 
    //         size = 10;
    //         break;
    //     case 2:
    //         size = 100;
    //         break;
    //     case 3: 
    //         size = 500;
    //         break;
    //     case 4: 
    //         size = 5000;
    //         break;
    //     case 5:
    //         size = 25000;
    //         break;
    //     case 6: 
    //         size = 100000;
    //         break;
    // }
    // //We can add a feature that if the size is less we use a "delete"
    // //So then we shave the array down to the correct size
    // int myArray[size];
    // for(int i=0;i<size;i++){
    //     myArray[i] = rand() % size +1;
    // }
    const int size = 10;
    int myitems[size] = {1,6,8,3,4,10,2,12,7,20};
    
    int *mysorteditems = mergeSort(myitems, size);
    // for(int i = 0; i < size; i++){
    //     mysorteditems[i] = quickSort(myitems, size)[i];
    // }
    printItems(mysorteditems, 10);

    //We can add a feature that if the size is less we use a "delete"
    //So then we shave the array down to the correct size

    //Task 2 
    auto t1 = Clock::now();
    // Put the Sort that is being used in between here:

    auto t2 = Clock::now();
    std::cout << "Delta t2-t1: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 -t1).count()<< " nanoseconds" << std::endl;
    
}