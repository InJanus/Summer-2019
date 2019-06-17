#include <iostream>
#include <stdio.h>       
#include <stdlib.h>     // srand, rand 
#include <time.h>       

#include "sort.h"
using namespace std;
//this is where the sort functions will go

//Bubble sort - brian (use)
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

//insertion sort -greg (use)
int *insertionSort(int myArray[]){
    int holder;
    int k;  
    int size = mysize(myArray);
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
}
//merge sort - brian (use)
//quick sort - greg

/* I think there needs to be 2 different temp Arrays coming out of this but the whole
Size thing is messing with me and the recurrsion will be called within the "J" if
statements for each of them but we also need to make an isSorted function I think */
int *quickSort(int myArray[]){
    int size = mysize(myArray);
    srand(time(0));
    int holder = rand() % size +1;;

    //Sort to the left and to the right of holder
    int tempArray[size]; //.size() .length() ect?
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
            }
            else{

            }
        }
    }
    if(isSorted(tempArray)){
        return tempArray;
    }
    quickSort(tempArray); 
}

//counting sort - brian
//radix sort - greg and brian

int *radixSort(int myArray){
    //int size = int(sizeof(myArray));

}

void printItems(int *items){
    for(int i =0; i < mysize(items); i++){
        cout << "i: " << i << " == " << items[i] << endl;
    }
}

int mysize(int *items){
    return(sizeof(items)/sizeof(int));
}

bool isSorted(int *items){
    for(int i = 0; i < mysize(items);i++){
        if(!(items[i] < items[i+1])){
            return false;
        }
    }
    return true;
}
