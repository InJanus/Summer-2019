#include "linked_list.h"
#include <iostream>
using namespace std;


linked_list::linked_list(){
    head = nullptr;
    pointer = nullptr;
}

student linked_list::getItem(int location){
    student *temp = head;
    
    if(location > size()){
        //return error
    }else{
        if(location == 0){
            student *returnVal = head;
            head = temp->next;
            return *returnVal;
        }else{
            for(int i = 0; i < location-2; i++){
                temp = temp->next;
            }
            student returnValue = *(temp->next);
            temp->next = temp->next->next;
            return returnValue;
        }
        //temp->next = temp->next->next;  //replaces the next value
    }
}

void linked_list::addItem(student stud){
    student *temp;
    student *temp2 = head;
    temp = new student;
    temp-> m_number = stud.m_number;
    temp-> firstName = stud.firstName;
    temp-> lastName = stud.lastName;
    temp-> birthday = stud.birthday;
    temp-> gpa = stud.gpa;
    if(temp->m_number < temp2->m_number){
        head = temp;
        head -> next = temp2;
    }
    else{
        bool flag = false;
        while(temp->m_number > temp2->next->m_number){
            if(temp2->next->next == nullptr){
                temp2 -> next -> next = temp;
                flag = true;
                break;
            }else{
                temp2 = temp2->next;
            }
        }
        if(!flag){
            temp -> next = temp2 ->next;
            temp2 -> next = temp;
        }
    }
}

int linked_list::size(){
    student *temp = head;
    int i = 0;
    if(temp == nullptr){
        return i;
    }else{
        i++;
        while(temp->next != nullptr){
            temp = temp->next;
            i++;
        }
        return i;
    }

    
}

int linked_list::isinList(int search){
    //returns the int of the location of the student, if not in list then returns -1
    //searches down the list of the .h file
    int location = -1;
    student *temp = head;
    for(int i = 0; i < size(); i++){
        location++;
        if(temp->m_number == search){
            return location;
        }else{
            temp = temp->next;
        }
    }
    //throw error for not in list
    return -1;
}

bool linked_list::isEmpty(){
    return(size() == 0);
}

student linked_list::seeNext(){
        if (isEmpty()){
            //Throw error
        }
        pointer = pointer->next;
    
    return *pointer;
}

student linked_list::seeAt(int location){
    student *temp = head;
    if (isEmpty()){
        //Throw error
    }
    for(int i = 0; i < location; i++){
            temp = temp->next;
        }
        pointer = temp;
        return *pointer;
}

void linked_list::reset(){
    pointer = head; 
}