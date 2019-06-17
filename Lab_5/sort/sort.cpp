#include <iostream>
#include <stdio.h>       
#include <stdlib.h>     // srand, rand 
#include <time.h>       

#include "sort.h"
using namespace std;
//this is where the sort functions will go

//Bubble sort - brian (use)
int* bubbleSort(int *items, int size){
    int *temp = items;
    int ammountSorted = 0;

    while(ammountSorted < size){
        for(int i = 0; i < size-ammountSorted-1; i++){
            if(temp[i+1] < temp[i]){
                //switch the items
                int temp2 = temp[i];
                temp[i] = temp[i+1];
                temp[i+1] = temp2;
            }
        }
        ammountSorted++;
    }
    return temp;
    //works
}

//insertion sort -greg (use)
int *insertionSort(int myArray[], int size){
    int holder;
    int k;  
    for (int i = 1; i < size; i++) {  
        holder = myArray[i];  
        k = i - 1;  

        //Find how far left to insert the holder number we have... if not found put at spot "0"
        //Also shift each value over to the right by 1
        while (k >= 0 && myArray[k] > holder) {  
            myArray[k + 1] = myArray[k];  
            k--;  
        }  
        myArray[k + 1] = holder;  
    }  
    return myArray;
    //works
}
//merge sort - brian (use)
int *merge(int *items, int *items2){
    int retval[2];
    if(items[0] > items2[0]){
        retval[0] = items[0];
        retval[1] = items2[0];
    }else if(items[0] <= items2[0]){
        retval[0] = items2[0];
        retval[1] = items[0];
    }
    return retval;
}

//merge sort - brian (use)
int *mergeSort(int *items, int size){
    //store the list of item locations of the merge sort
    if(size == 1){
        return items;
    }else{
        int l1[size/2];
        int l2[size/2];
        for(int i = 0; i < size/2; i++){
            l1[i] = items[i];
            l2[i] = items[(i+size/2)];
        }

        //first split the array
        for(int i = 0; i < size/2; i++){
            l1[i] = mergeSort(l1, size/2)[i];
            l2[i] = mergeSort(l2, size/2)[i];
        }
        return(merge(l1,l2));
    }
}
//quick sort - greg
bool isSorted(int *items, int size){
    for(int i = 0; i < size-1;i++){
        if(!(items[i] < items[i+1])){
            return false;
        }
    }
    return true;
}

int *quickSort(int myArray[], int size){
    int holder = rand() % size +1;
    int *tempArray = myArray;
    int loc = 0;
    for(int j = 0; j < 3;j++){
        for(int i = 0; i < size; i++){
            //j=0 less than holder
            if(myArray[i] < holder && j == 0){
                tempArray[loc]=myArray[i];
                loc ++;
            }
            //j=1 equal to holder
            else if(myArray[i] == holder && j == 1){
                tempArray[loc] = myArray[i];
                loc++;
            }
            //j=2 greater than holder
            else if(myArray[i] > holder && j == 2){
                tempArray[loc] = myArray[i];
                loc++;
            }
        }
    }
    if(isSorted(tempArray, size)){
        return tempArray;
    }
    printItems(tempArray, size);
    quickSort(tempArray, size); 
}

//counting sort - brian
void countingSort(int myArray,int size) {

}
//radix sort - greg and brian
int *radixSort(int myArray,int size){

}

void printItems(int *items, int size){
    for(int i =0; i < size; i++){
        cout << "i: " << i << " == " << items[i] << endl;
    }
}


