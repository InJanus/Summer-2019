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
        for(int i = 0; i < location-1; i++){
            temp = temp->next;
        }
        //Hey I think this returns not the item at the location but the next -Greg
        student returnValue = *(temp->next);
        //temp->next = temp->next->next;  //replaces the next value
        return returnValue;
    }
}

void linked_list::addItem(student stud){
    student *temp = head;
    head = new student;
    head -> next = temp;
    head-> m_number = stud.m_number;
    head-> firstName = stud.firstName;
    head-> lastName = stud.lastName;
    head-> gpa = stud.gpa;
}

int linked_list::size(){
    student *temp = head;
    int i = 0;
    while(temp->next != nullptr){
        temp = temp->next;
        i++;
        cout << i << endl;
    }
    return i;
}

bool linked_list::isinList(student search){
    //returns the int of the location of the student, if not in list then returns -1
    //searches down the list of the .h file
    int location = -1;
    student *temp = head;
    for(int i = 0; i < size(); i++){
        location++;
        if(temp->m_number == search.m_number){
            return location;
        }else if(temp->firstName == search.firstName){
            return location;
        }else if(temp->lastName == search.lastName){
            return location;
        }else if(temp->birthday == search.birthday){
            return location;
        }else if(temp->gpa == search.gpa){
            return location;
        }
        else{
            temp = temp->next;
        }
    }
    return -1;
}

bool linked_list::isEmpty(){
    return(size() == 0);
}

//2 calls confuses me 
student linked_list::seeNext(int location){
    if(pointer == head){
        student *temp = head;
        if (isEmpty()){
            //Throw error
        }
        for(int i = 0; i < location-1; i++){
                temp = temp->next;
            }
        pointer = temp->next;
        }else{
            pointer = pointer->next;
        }
    
    return *pointer;
}

student linked_list::seeAt(int location){
    student *temp = head;
    if (isEmpty()){
        //Throw error
    }
    for(int i = 0; i < location-1; i++){
            temp = temp->next;
        }
        pointer = temp;
        return *pointer;
}

void linked_list::reset(){
    pointer = head; 
}