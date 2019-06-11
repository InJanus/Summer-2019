#include "classes_s.h"
#include <iostream>
using namespace std;

classes_s::classes_s(){
    mysize = 20;
    linked_list2();
}

classes_s::classes_s(int size){
    mysize = size;
    linked_list2();
}

void classes_s::addItem(student stud){
    if(mysize > size()){
        linked_list2::addItem(stud, true);
    }else{
        cout << "list out of bounds" << endl;
    }
}

student classes_s::getItem(){
    return linked_list2::getItem(size()-1);
}

bool classes_s::isEmpty(){
    return linked_list2::isEmpty();
}

bool classes_s::isFull(){
    return (linked_list2::size() == mysize);
}

int classes_s::size(){
    return linked_list2::size();
}

void classes_s::clearList(){
    student temp;
    for(int i = 0; i < size(); i++){
        temp = linked_list2::getItem(0);
    }
}

int classes_s::getMaxSize(){
    return mysize;
}