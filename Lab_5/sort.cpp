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
//Bubble sort - brian
//insertion sort -greg
//merge sort - brian
//quick sort - greg
//counting sort - brian
//radix sort - greg


