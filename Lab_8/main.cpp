#include <iostream>
#include "..\\Lab_8\pqueue\pqueue.h"
//#include "..\\Lab_8\heap\heap.h"
//#include <stdio.h>       
//#include <stdlib.h>     
//#include <time.h>       
//#include <chrono>
//typedef std::chrono::high_resolution_clock Clock;
using namespace std;



int main(){

    cout<<"Hello main Bitches"<<endl;

    PQueue test;
    //cout<<"size: " <<test.getSize()<<endl;
    test.insert(16);
    test.insert(30);
    test.insert(20);
    test.insert(5);
    test.printQueue();
    //test.insert(30);
    //test.printQueue();
    cout<<"size: " <<test.getSize()<<endl;





}