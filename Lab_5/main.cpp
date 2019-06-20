//main
#include <iostream>
#include ".\\sort\sort.h"
#include ".\\linked_list\linked_list.h"
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
    // cout << "Size of array: \n 1) 10 \n 2) 100 \n 3) 500 \n 4) 5000 \n 5) 25000 \n 6) 100000 " <<endl;
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
    srand(time(0));
    int size = 50;
    int count = 1;
    linked_list mylist;
    for(int i=0;i<size;i++){
        student temp;
        temp.m_number = rand()%50+1;
        temp.firstName = rand()%26+65;
        temp.lastName = rand()%26+65;


        mylist.addItem(temp);
        count++;
    }

    for(int i = 0; i < size; i++){
        cout << mylist.seeAt(i).lastName << endl;
    }

    // int pick;
    // cout << "Pick a sort (1)bubble (2)bubble reverse (3)radix (4)radix reverse" << endl;
    // cin >> pick;
    // switch(pick){
    //     case 1:
    //         mylist.bubbleSort_mn();
    //         break;
    //     case 2:
    //         mylist.bubble_flip_mn();
    //         break;
    //     case 3:
    //         mylist.radixSort();
    //         break;
    //     case 4:
    //         mylist.radix_flip();
    //         break;
    // }
    mylist.insertionSort_mn();

    cout << endl << endl << endl;
    
    for(int i = 0; i < size; i++){
        // cout << mylist.seeAt(i).lastName << endl;
    }
    //bubble
    //insercion
    //merge
    


}