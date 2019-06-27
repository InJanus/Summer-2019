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

    int pick;
    cout << "Pick a sort (1)First Name (2)First Name reverse (3)Last Name (4)Last Name reverse (5)MNumber (6)Mnumber reverse" << endl;
    cin >> pick;
    switch(pick){
        case 1:
            mylist.bubbleSort();
            break;
        case 2:
            mylist.bubble_flip();
            break;
        case 3:
            mylist.insertionSort();
            break;
        case 4:
            mylist.insertion_flip();
            break;
        case 5:
            mylist.radixSort();
            break;
        case 6:
            mylist.radix_flip();
            break;
    }
    cout << "ID :  F  :  L" << endl;
    cout << "-------------" << endl;
    for(int i = 0; i < size; i++){
        if(mylist.seeAt(i).m_number < 10){
            cout << mylist.seeAt(i).m_number << "  :  ";
        }else{
            cout << mylist.seeAt(i).m_number << " :  ";
        }
        cout << mylist.seeAt(i).firstName << "  :  ";
        cout << mylist.seeAt(i).lastName << "\n";
    }
}