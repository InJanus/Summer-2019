#include "linked_list.h"
#include <iostream>
#include <math.h>
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
    student *temp2 = head;
    student *temp = new student;
    temp-> m_number = stud.m_number;
    temp-> firstName = stud.firstName;
    temp-> lastName = stud.lastName;
    if(temp2 == nullptr){
        head = temp;
    }else{
        while(temp2-> next != nullptr){
            temp2 = temp2->next;
        }

        temp2->next = temp;
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
        mylocation = location;
        return *temp;
    }
}

void linked_list::reset(){
    mylocation = 0; 
}

void linked_list::bubbleSort(){
    int ammountSorted = 0;
    student *temp = head;
    student tempdata;
    bool flag = false;
    bool stop = false;
    int count = 0;

    while(!stop){
        if(temp->firstName.compare(temp->next->firstName) < 0){
            //switch the items
            tempdata.m_number = temp->m_number;
            tempdata.firstName = temp->firstName;
            tempdata.lastName = temp->lastName;
            temp->m_number = temp->next->m_number;
            temp->firstName = temp->next->firstName;
            temp->lastName = temp->next->lastName;
            temp->next->m_number = tempdata.m_number;
            temp->next->firstName = tempdata.firstName;
            temp->next->lastName = tempdata.lastName;
            
        }else{
            count++;
        }

        if(count == size()-1){
            stop = true;
        }
        if(temp->next->next == nullptr){
            temp = head;
            count = 0;
        }else{
            temp = temp->next;
        }

    }
    
}

bool linked_list::isSorted(){
    student *temp = head;
    for(int i = 0; i < size(); i++){
        if(temp->m_number > temp->next->m_number){
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void linked_list::quickSort(){
    int holder = rand() % size()+1;
    student *tempArray = head;
    student *tempArrayHead;
    student *temp = head;
    int holderMnumber;
    for(int i = 0; i < holder; i++){
        temp = temp->next;
        holderMnumber = temp->m_number;
    }
    tempArrayHead = tempArray;
    for(int j = 0; j < 3;j++){
        for(int i = 0; i < size()-1; i++){
            //j=0 less than holder
            if(temp->m_number < holderMnumber && j == 0){
                tempArray->m_number = temp->m_number;
                tempArray->firstName = temp->firstName;
                tempArray->lastName = temp->lastName;
                tempArray = tempArray->next;
            }
            //j=1 equal to holder
            else if(temp->m_number == holderMnumber && j == 1){
                tempArray->m_number = temp->m_number;
                tempArray->firstName = temp->firstName;
                tempArray->lastName = temp->lastName;
                tempArray = tempArray->next; 
            }
            //j=2 greater than holder
            else if(temp->m_number > holderMnumber && j == 2){
                tempArray->m_number = temp->m_number;
                tempArray->firstName = temp->firstName;
                tempArray->lastName = temp->lastName;
                tempArray = tempArray->next; 
            }
            temp = temp->next;
        }
        
    }
    head = tempArray;
    if(isSorted()){
        return;
    }
    quickSort(); 

}

void linked_list::radixSort(){
    student *temp = head;
    student tempdata;
    bool flag = false;
    bool stop = false;
    int count = 0;

    //int digit = int(log10(size()*2));
    int digit = 1;
        for(int j = 0; j <= digit; j++){
            stop = false;
            while(!stop){
                if((temp->next->m_number/int(pow(10,j)))%10 < (temp->m_number/int(pow(10,j)))%10){
            //switch the items
                    tempdata.m_number = temp->m_number;
                    tempdata.firstName = temp->firstName;
                    tempdata.lastName = temp->lastName;
                    temp->m_number = temp->next->m_number;
                    temp->firstName = temp->next->firstName;
                    temp->lastName = temp->next->lastName;
                    temp->next->m_number = tempdata.m_number;
                    temp->next->firstName = tempdata.firstName;
                    temp->next->lastName = tempdata.lastName;
            
                }else{
                    count++;
                }

                if(count == size()-1){
                    stop = true;
                }
                if(temp->next->next == nullptr){
                    temp = head;
                    count = 0;
                }else{
                    temp = temp->next;
                }
                
            }

        }
}

void linked_list::bubble_flip(){
    int ammountSorted = 0;
    student *temp = head;
    student tempdata;
    bool flag = false;
    bool stop = false;
    int count = 0;

    while(!stop){
        if(temp->firstName.compare(temp->next->firstName) > 0){
            //switch the items
            tempdata.m_number = temp->m_number;
            tempdata.firstName = temp->firstName;
            tempdata.lastName = temp->lastName;
            temp->m_number = temp->next->m_number;
            temp->firstName = temp->next->firstName;
            temp->lastName = temp->next->lastName;
            temp->next->m_number = tempdata.m_number;
            temp->next->firstName = tempdata.firstName;
            temp->next->lastName = tempdata.lastName;
            
        }else{
            count++;
        }

        if(count == size()-1){
            stop = true;
        }
        if(temp->next->next == nullptr){
            temp = head;
            count = 0;
        }else{
            temp = temp->next;
        }

    }
    
}

void linked_list::radix_flip(){
    student *temp = head;
    student tempdata;
    bool flag = false;
    bool stop = false;
    int count = 0;

    //int digit = int(log10(size()*2));
    int digit = 1;
        for(int j = 0; j <= digit; j++){
            stop = false;
            while(!stop){
                if((temp->next->m_number/int(pow(10,j)))%10 > (temp->m_number/int(pow(10,j)))%10){
            //switch the items
                    tempdata.m_number = temp->m_number;
                    tempdata.firstName = temp->firstName;
                    tempdata.lastName = temp->lastName;
                    temp->m_number = temp->next->m_number;
                    temp->firstName = temp->next->firstName;
                    temp->lastName = temp->next->lastName;
                    temp->next->m_number = tempdata.m_number;
                    temp->next->firstName = tempdata.firstName;
                    temp->next->lastName = tempdata.lastName;
            
                }else{
                    count++;
                }

                if(count == size()-1){
                    stop = true;
                }
                if(temp->next->next == nullptr){
                    temp = head;
                    count = 0;
                }else{
                    temp = temp->next;
                }
                
            }

        }
}
