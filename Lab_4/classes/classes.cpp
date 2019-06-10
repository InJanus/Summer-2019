#include "classes.h"
#include <iostream>
using namespace std;

classes::classes(){
    mysize = 20;
    linked_list2();
}

classes::classes(int size){
    mysize = size;
    linked_list2();
}

void classes::addItem(student stud){
    if(mysize > size()){
        linked_list2::addItem(stud, true);
    }else{
        cout << "list out of bounds" << endl;
    }
}

student classes::getItem(){
    return linked_list2::getItem(0);
}

bool classes::isEmpty(){
    return linked_list2::isEmpty();
}

bool classes::isFull(){
    return (linked_list2::size() == mysize);
}

int classes::size(){
    return linked_list2::size();
}

void classes::clearList(){
    student temp;
    for(int i = 0; i < size(); i++){
        temp = linked_list2::getItem(0);
    }
}

int classes::getMaxSize(){
    return mysize;
}