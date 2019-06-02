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
    //birthday
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

int linked_list::isinList(student search){

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
        }
        temp = temp->next;
    }
    
}