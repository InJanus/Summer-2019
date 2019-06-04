#include "linked_list.h"
#include <iostream>
using namespace std;

void throwError(string message){
    try{
        throw runtime_error(message);
    }catch(exception& e){
        cerr << e.what() << endl;
    }
}


linked_list::linked_list(){
    head = nullptr;
    mylocation = 0;
}

student linked_list::getItem(int location){
    student *temp = head;
    
    if(location > size()){
        throwError("Location not inside list");
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
    if(temp2 == nullptr){
        head = temp;
    }else{
        if(temp->m_number < temp2->m_number){
            head = temp;
            head -> next = temp2;
        }
        else{
            bool flag = false;
            if(temp2->next == nullptr){
                temp2 -> next = temp;
                flag = true;
            }else{
                while(temp->m_number > temp2->next->m_number){
                    if(temp2->next->next == nullptr){
                        temp2 -> next -> next = temp;
                        flag = true;
                        break;
                    }else{
                        temp2 = temp2->next;
                    }
                }
            }
            if(!flag){
                temp -> next = temp2 ->next;
                temp2 -> next = temp;
            }
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
    throwError("not in list");
    return -1;
}

bool linked_list::isEmpty(){
    return(size() == 0);
}

student linked_list::seeNext(){
    if (isEmpty()){
        throwError("list is empty");
    }else{
        // if(pointer == nullptr){
        //     return *pointer;
        // }else{
        //     pointer = pointer->next;
        //     return *pointer;
        // }
        student retval = seeAt(mylocation);
        if(retval.next == nullptr){
            //still has a value but end of list
            throwError("End of list");
        }else{
            mylocation++;
        }
        return retval;
    }
}

student linked_list::seeAt(int location){
    student *temp = head;
    if (isEmpty()){
        throwError("list is empty");
    }else{
        for(int i = 0; i < location; i++){
                temp = temp->next;
                
        }
        mylocation = (location+1);
        return *temp;
    }
}

void linked_list::reset(){
    mylocation = 0; 
}