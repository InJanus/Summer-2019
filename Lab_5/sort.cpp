#include <iostream>
using namespace std;
#include <stdio.h>      // printf, scanf, puts, NULL 
#include <stdlib.h>     // srand, rand 
#include <time.h>       // time 

//this is where the sort functions will go

//random genaration
int *randomGenerate(int n){
    int myArray[10];

    for(int i=0;i<n;i++){
        myArray[i] = rand() % n +1;
    }

    return myArray;
}
//Bubble sort - brian (use)
//insertion sort -greg (use)
int *insertionSort(int myArray[], int n){
    int holder;
    int k;  
    for (int i = 1; i < n; i++) {  
        holder = myArray[i];  
        k = i - 1;  

        //Find how far left to insert the holder number we have... if not found put at 0
        //Also shift each value over to the right by 1
        while (k >= 0 && myArray[k] > holder) {  
            myArray[k + 1] = myArray[k];  
            k--;  
        }  
        myArray[k + 1] = holder;  
    }  
}
//merge sort - brian (use)
//quick sort - greg

//counting sort - brian
//radix sort - greg

int* bubbleSort(int *items){
    int ammountSorted = 0;
    int size = int(sizeof(items));
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
    for(int i =0; i < int(sizeof(items)); i++){
        cout << "i: " << i << " == " << items[i] << endl;
    }
}
