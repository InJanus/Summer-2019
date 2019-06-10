#include "classes.h"

classes::classes(){
    mysize = 20;
    linked_list2::linked_list2();
}

classes::classes(int size){
    mysize = size;
    linked_list2::linked_list2();
}

void classes::addItem(student stud){
    
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