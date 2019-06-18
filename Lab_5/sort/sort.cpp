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
int *merge(int *items, int *items2, int size, int size2){
    int retval[size+size2];
    int count = 0;
    int astart, bstart;
    astart = 0;
    bstart = 0;
    if(astart == size){
        retval[count] = items2[bstart];
        count++;
        bstart++;
    }else if(bstart == size){
        retval[count] = items[astart];
        count++;
        astart++;
    }else if(items[astart] > items2[bstart]){
        retval[count] = items2[bstart];
        count++;
        bstart++;
    }else if(items[astart] <= items2[bstart]){
        retval[count] = items[astart];
        count++;
        astart++;
    }
    return retval;
}

//merge sort - brian (use)
int *mergeSort(int *items, int size){
    //store the list of item locations of the merge sort
    int size1, size2;
    if(size == 1){
        return items;
    }else{

        if(size%2 == 1){
            size1 = (size+1)/2;
        }else{
            size1 = size/2;
        }
        size2 = size/2;
        int *l1 = new int[size1];
        int *l2 = new int[size2];

        for(int i = 0; i < size1; i++){
            l1[i] = items[i];
        }
        for(int i = 0; i < size2; i++){
            l2[i] = items[(i+size2)];
        }

        //first split the array
        for(int i = 0; i < size/2; i++){
            l1[i] = mergeSort(l1, size/2)[i];
            l2[i] = mergeSort(l2, size/2)[i];
        }
        return(merge(l1,l2, size1, size2));
    }
}
//quick sort - greg
bool isSorted(int *items, int size){
    for(int i = 0; i < size-1;i++){
        if(!(items[i] <= items[i+1])){
            return false;
        }
    }
    return true;
}

int *quickSort(int myArray[], int size){
    //establish the piece the spot to make things go to the left and right of.
    int holder = rand() % size +1;
    int tempArray[size];
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

int *countingSort(int *items, int size){
    int *myitems = new int[size*2];
    int *retval = new int[size];
    for(int i = 0; i < size*2; i++){
        myitems[i] = 0;
    }
    for(int i = 0; i < size;i++){
        myitems[items[i]-1]++;
    }

    bool stop = false;
    int count = 0;
    int i = 0;
    while(!stop){
        if(myitems[count] >= 1){
            retval[i] = count+1;
            myitems[count]--;
            i++;
        }else if(myitems[count] == 0){
            count++;
        }else if(count == (size*2)){
            stop = true;
        }
    }
    return retval;

}


//counting sort - brian
int *countingSort(int myArray[],int size, int digit) {
    // Declaring tempArray to put the number back into and count to figure out how many of each digit
	int tempArray[size];
    int count[10];
 
	// Count the number of times each digit occurred
	for (int i = 0; i < size; i++){
		count[(myArray[i] / digit) % 10]++;
    }
 
	// Calculate the total count
	for (int i = 1; i < 10; i++){
		count[i] += count[i-1];
    }
	// Inserting values according to the digit
	for (int i = size - 1; i >= 0; i--)
	{
		tempArray[count[(myArray[i] / digit) % 10] - 1] = myArray[i];
		count[(myArray[i] / digit) % 10]--;
	}
 
	return tempArray;
}
//radix sort - greg and brian
int *radixSort(int myArray[],int size){
    int maxData = myArray[0];
    for (int i = 1; i < size; i++){
		if (myArray[i] > maxData){
			maxData = myArray[i];
        }
    }
    //Choose what digit we are dealing with starting with least significant (1) and going to maxData's largest digit.
    //This is assuming code takes 1 and makes it xxx1 (x being amount of digits)
    for(int digit = 1; maxData/digit > 0; digit*10){
        myArray = countingSort(myArray,10,digit);
    }
    return myArray;
}

void printItems(int *items, int size){
    for(int i =0; i < size; i++){
        cout << "i: " << i << " == " << items[i] << endl;
    }
}


