#include "linked_list.h"
#include <iostream>
using namespace std;

linked_list::linked_list(){
    head = nullptr;
    mylocation = 0;
}

bigdata linked_list::getItem(int location){
    bigdata *temp = head;
    
    if(location > size()){
        cout << "Location not inside list" << endl;
    }else{
        if(location == 0){
            bigdata *returnVal = head;
            head = temp->next;
            return *returnVal;
        }else{
            for(int i = 0; i < location-2; i++){
                temp = temp->next;
            }
            bigdata returnValue = *(temp->next);
            temp->next = temp->next->next;
            return returnValue;
        }
        //temp->next = temp->next->next;  //replaces the next value
    }
    return bigdata();
}

void linked_list::addItem(string stud){
    bigdata *temp;
    bigdata *temp2 = head;
    temp = new bigdata;
    temp-> name = stud;
    if(temp2 == nullptr){
        head = temp;
    }else{
        if(temp->name < temp2->name){
            head = temp;
            head -> next = temp2;
        }
        else{
            bool flag = false;
            if(temp2->next == nullptr){
                temp2 -> next = temp;
                flag = true;
            }else{
                while(temp->name > temp2->next->name){
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
    bigdata *temp = head;
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

int linked_list::isinList(string search){
    //returns the int of the location of the student, if not in list then returns -1
    //searches down the list of the .h file
    int location = -1;
    bigdata *temp = head;
    for(int i = 0; i < size(); i++){
        location++;
        if(temp->name == search){
            return location;
        }else{
            temp = temp->next;
        }
    }
    //cout << "not in list" << endl;
    return -1;
}

bool linked_list::isEmpty(){
    return(size() == 0);
}

bigdata linked_list::seeNext(){
    if (isEmpty()){
        cout << "list is empty" << endl;
    }else{
        // if(pointer == nullptr){
        //     return *pointer;
        // }else{
        //     pointer = pointer->next;
        //     return *pointer;
        // }
        bigdata retval = seeAt(mylocation);
        if(retval.next == nullptr){
            //still has a value but end of list
            //cout << "End of list" << endl;
        }else{
            mylocation++;
        }
        return retval;
    }
    return bigdata();
}

bigdata linked_list::seeAt(int location){
    bigdata *temp = head;
    if (isEmpty()){
        cout << "list is empty" << endl;
    }else{
        for(int i = 0; i < location; i++){
                temp = temp->next;
                
        }
        mylocation = location;
        return *temp;
    }
    return bigdata();
}

void linked_list::reset(){
    mylocation = 0; 
}

void linked_list::removeAll(){
    delete head;
    head = nullptr;
}

bool linked_list::equalto(linked_list input){
    if(size() == input.size()){
        for(int i = 0; i < size(); i++){
            if(i != isinList(input.seeAt(i).name)){
                return false;
            }
        }
        return true;
    }
    return false;
}