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

game linked_list::getItem(int location){
    game *temp = head;
    
    if(location > size()){
        throwError("Location not inside list");
    }else{
        if(location == 0){
            game *returnVal = head;
            head = temp->next;
            return *returnVal;
        }else{
            for(int i = 0; i < location-2; i++){
                temp = temp->next;
            }
            game returnValue = *(temp->next);
            temp->next = temp->next->next;
            return returnValue;
        }
        //temp->next = temp->next->next;  //replaces the next value
    }
}

void linked_list::addItem(game stud){
    game *temp;
    game *temp2 = head;
    temp = new game;
    temp-> year = stud.year;
    temp-> result = stud.result;
    if(temp2 == nullptr){
        head = temp;
    }else{
        if(temp->year < temp2->year){
            head = temp;
            head -> next = temp2;
        }
        else{
            bool flag = false;
            if(temp2->next == nullptr){
                temp2 -> next = temp;
                flag = true;
            }else{
                while(temp->year > temp2->next->year){
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
    game *temp = head;
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
    //returns the int of the location of the game, if not in list then returns -1
    //searches down the list of the .h file
    int location = -1;
    game *temp = head;
    for(int i = 0; i < size(); i++){
        location++;
        if(temp->year == search){
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

game linked_list::seeNext(){
    if (isEmpty()){
        throwError("list is empty");
    }else{
        // if(pointer == nullptr){
        //     return *pointer;
        // }else{
        //     pointer = pointer->next;
        //     return *pointer;
        // }
        game retval = seeAt(mylocation);
        if(retval.next == nullptr){
            //still has a value but end of list
            throwError("End of list");
        }else{
            mylocation++;
        }
        return retval;
    }
}

game linked_list::seeAt(int location){
    game *temp = head;
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

void linked_list::reset(){
    mylocation = 0; 
}

bool linked_list::isEqual(linked_list indata){
    if(size() == indata.size()){
        for(int i = 0; i < size(); i++){
            if(!((seeAt(i).year == indata.seeAt(i).year)&&(seeAt(i).result == indata.seeAt(i).result))){
                return false;
            }
        }
        return true;    
    }
    return false;
}