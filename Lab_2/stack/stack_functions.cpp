#include "stack.h"
#include <iostream>
#include <exception>

using namespace std;

stack::stack(){
    top = 0;
    maxSize = 25;
}

void stack::print(){
    for(int i = 0; i < top; i++){
        cout << dataArray[i] << endl;
    }
}
void stack::printString(){
    for(int i = 0; i < top; i++){
        cout << char(dataArray[i]) << endl;
    }
}

//push function to add a number to the end of the array
    void stack::push(int num){
        if (top == maxSize + 1){
            try{
                throw runtime_error("Stack Overflow");
            }catch(exception& e){
                cerr << "caught " << e.what() << endl;
            }
        }
        dataArray[top] = num;
        top++;
    }

//pop function to remove the last value of an array and return it
    int stack::pop(){
        if(top == 0){
            try{
                throw runtime_error("Stack Underflow");
            }catch(exception& e){
                cerr << "caught " << e.what() << endl;
            }
        } else {
            top--;
            int retval = dataArray[top];
            return retval;
        }
    }

//top function to return the last value in the array
    int stack::topper(){
        if(top == 0){
            throw "Stack Underflow";
        }
        return dataArray[top-1];
    }

//length function returns the length of the stack
    int stack::length(){
        if(top == 0){
            throw "Stack Underflow";
        }
        return top;
    }