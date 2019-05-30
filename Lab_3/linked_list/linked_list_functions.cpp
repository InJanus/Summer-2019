#include "linked_list.h"
#include <iostream>
using namespace std;


linked_list::linked_list(){
    head = nullptr;
}

student linked_list::getItem(int location){
    student *temp = head;
    if(location > size()){
        //return error
    }else{
        for(int i = 0; i < location-1; i++){
            temp = temp->next;
        }
        student returnValue = *(temp->next);
        temp->next = temp->next->next;  //replaces the next value
        return returnValue;
    }
}