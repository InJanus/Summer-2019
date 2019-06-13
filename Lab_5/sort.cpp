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


