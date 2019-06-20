#include <iostream>
#include <stdio.h>       
#include <stdlib.h>     // srand, rand 
#include <time.h>   
#include <math.h>       //log10      

#include "sort.h"
using namespace std;
//this is where the sort functions will go

//Bubble sort - a very simple algorithm that compares each item with each other item to put them in the
//right order. Its called bubble sort because the smallest (or largest) items bubble to the top.
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

//insertion sort - a simple algorithm that builds the final list 1 item at a time
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
//merge the stuff back together
int *merge(int *items, int *items2, int size, int size2){
    int *retval = new int[(size+size2)];
    int count = 0;
    int astart, bstart;
    astart = 0;
    bstart = 0;
    for(int i = 0; i < (size+size2); i++){
        if(astart == size){
            retval[count] = items2[bstart];
            count++;
            bstart++;
        }else if(bstart == size2){
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
    }
    return retval;
}

//merge sort - a recursive, divide and conquer algorithm. It is an efficient algorithm compared to bubble
//and insertion sort.
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
            l2[i] = items[(i+size1)];
        }

        l1 = mergeSort(l1, size1);
        l2 = mergeSort(l2, size2);
        return(merge(l1,l2, size1, size2));
    }
}

bool isSorted(int *items, int size){
    for(int i = 0; i < size-1;i++){
        if(!(items[i] <= items[i+1])){
            return false;
        }
    }
    return true;
}

//quick sort - another divide and conquer
int *quickSort(int myArray[], int size){
    //establish the piece the spot to make things go to the left and right of.
    int holder = rand() % size +1;
    int *tempArray = new int[size];
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
    quickSort(tempArray, size); 
}

//counting sort : an algorithm for sorting items when they are small(ish) integers (at least the sort key is).
//This is not an in-place sort. The output is a new array.
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

<<<<<<< HEAD
int *countingSort(int myArray[],int size, int digit) {
    // Declaring tempArray to put the number back into and count to figure out how many of each digit
    int *tempArray = new int[size];
    int *count = new int[10];
 
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
=======
>>>>>>> 3f4b8f6a0aaa1287173ffc7ed5d41dce8651a2cc
//radix sort - Srts least significant digit first then goes through the larger ones
//it just works
int *radixSort(int myArray[],int size){

    //Choose what digit we are dealing with starting with least significant (1) and going to maxData's largest digit.
    //This is assuming code takes 1 and makes it xxx1 (x being amount of digits)

<<<<<<< HEAD
    
   int digit = int(log10(size*2));
=======
    int digit = int(log10(size*2));
>>>>>>> 3f4b8f6a0aaa1287173ffc7ed5d41dce8651a2cc
    int *retval = new int[size];
        for(int i = 0; i < size; i++){
            retval[i] = myArray[i];
        }
        int ammountSorted = 0;
        for(int j = 0; j <= digit; j++){
            ammountSorted = 0;
            while(ammountSorted < size){
                for(int i = 0; i < size-ammountSorted-1; i++){
                    if((retval[i+1]/int(pow(10,j)))%10 < (retval[i]/int(pow(10,j)))%10){
                        //switch the items
                        int temp2 = retval[i];
                        retval[i] = retval[i+1];
                        retval[i+1] = temp2;
                    }
            }
            ammountSorted++;
            }
        }
    return retval;
}

void printItems(int *items, int size){
    for(int i =0; i < size; i++){
        cout << "i: " << i << " == " << items[i] << endl;
    }
}

