#include "linked_list2.h"
#include <iostream>
using namespace std;

#include "reused_classes/reused.cpp"

linked_list2::linked_list2(){
    head = nullptr;
    mylocation = 0;
}

student linked_list2::getItem(int location){
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

void linked_list2::addItem(student stud, bool unordered){
    student *temp;
    student *temp2 = head;
    if(unordered){
        /* ADDS TO THE FRONT
        head = new student;
        head -> next = temp2;
        head-> m_number = stud.m_number;
        head-> firstName = stud.firstName;
        head-> lastName = stud.lastName;
        head-> gpa = stud.gpa;
        */

       //ADD TO THE BACK
        temp = new student;
        temp-> m_number = stud.m_number;
        temp-> firstName = stud.firstName;
        temp-> lastName = stud.lastName;
        temp-> gpa = stud.gpa;
        if(temp2 == nullptr){
            head = temp;
        }else{
            while(temp2-> next != nullptr){
                temp2 = temp2->next;
            }

            temp2->next = temp;
        }

    }else{
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
}

int linked_list2::size(){
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

int linked_list2::isinList(int search){
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

bool linked_list2::isEmpty(){
    return(size() == 0);
}

student linked_list2::seeNext(){
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

student linked_list2::seeAt(int location){
    student *temp = head;
    if (isEmpty()){
        throwError("list is empty");
    }else{
        for(int i = 0; i < location; i++){
                temp = temp->next;
                
        }
        mylocation = location;
        return *temp;
    }
}

void linked_list2::reset(){
    mylocation = 0; 
}