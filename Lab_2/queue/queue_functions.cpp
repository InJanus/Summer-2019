#include "queue.h"
#include <iostream>

using namespace std;

queue::queue(){
    myend = 0;
    maxsize = 25;
}

//prints all values in queue
void queue::print(){
    for(int i = 0; i < myend; i++){
        cout << data[i] << endl;
    }
}

//prints all values in queue using their characters
void queue::printString(){
    for(int i = 0; i < myend; i++){
        cout << char(data[i]);
    }
}

//putting data in the queue
void queue::enqueue(int indata){
    if(myend <= 25){
        data[myend] = indata;
        myend++;
    } else {
        try{
            throw runtime_error("Queue Overflow");
        }catch(exception& e){
            cerr << e.what() << endl;
        }
    }
}

//removing data from the queue
int queue::dequeue(){
    if(myend > 0){
        //based off our compiler, we could not use just throw "Queue Underflow" therefore we need to do it this way to get arround the compiler bug
        int temp = data[0];
        for(int i = 1; i < myend; i++){
            data[i-1] = data[i];
        }
        myend--;
        return temp;
    } else {
        try{
            throw runtime_error("Queue Underflow");
        }catch(exception& e){
            cerr << e.what() << endl;
        }
        return 0;
    }
}

//checking if queue is full
bool queue::isFull(){
    return((myend-1) >= maxsize);
}

//checking if queue is empty
bool queue::isEmpty(){
    return(myend==0);
}

//finding the queue length
int queue::length(){
    return(myend-1);
}
