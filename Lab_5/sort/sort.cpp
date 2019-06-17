#include <iostream>
#include <stdio.h>      // printf, scanf, puts, NULL 
#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 

#include "sort.h"
using namespace std;
//this is where the sort functions will go

int mysize(int *items){
    return (sizeof(items)/sizeof(int));
}

void randomGenerate(int *myArray){

    // int myArray[n];

    for(int i=0;i<100;i++){
        myArray[i] = rand() % (100*2) +1;
        cout << myArray[i] << endl;
    }

    // return myArray;
}
//Bubble sort - brian
//insertion sort -greg
//merge sort - brian
//quick sort - greg
//counting sort - brian
//radix sort - greg

int* bubbleSort(int *items){
    int ammountSorted = 0;
    int size = mysize(items);
    while(ammountSorted < size){
        for(int i = 0; i < size-ammountSorted-1; i++){
            if(items[i+1] < items[i]){
                //switch the items
                int temp = items[i];
                items[i] = items[i+1];
                items[i+1] = temp;
            }
        }
        ammountSorted++;
    }
}

void printItems(int *items){
    for(int i =0; i < mysize(items); i++){
        cout << "i: " << i << " == " << items[i] << endl;
    }
}


