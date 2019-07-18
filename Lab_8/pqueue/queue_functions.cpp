#include "pqueue.h"
#include <iostream>
using namespace std;

void PQueue::insert(int inVal){             //FIXME need to do it so that the insert is in the right place 
    // Node *temp = first;
    // if (first == nullptr){
    //     first =new Node;
    //     first->data = inMnum;
    // }else{
    //     Node *current = new Node;
    //     while (temp->next != nullptr){
    //         current->next = temp;
    //         temp = temp->next;
    //     }
    //     temp->next = new Node; //if we are at the last node
    //     temp->next->data = inMnum;
    // }
    // length++;

    Node *temp = first;
    if (first == nullptr){
        first =new Node;
        first->data = inVal;
    }
    else if(inVal > first->data){ 
        Node* inNode= new Node;    //case where the inserted Node is > first
        inNode->data=inVal;
        inNode->next= first;
        first =inNode;
    }
    else if(inVal<first->data && temp->next== nullptr){
        Node *inNode = new Node;  //case where the inserted Node is the second Node to be entered
        inNode->data=inVal;
        first->next = inNode;
    }
    else{
        Node *previous=nullptr;
        int count=0;
        while (temp->next != nullptr && temp->data > inVal){ // traverse the list for the value that is right 
            previous = temp;
            temp = temp->next;
            count++;
        }
        if(temp->data<= inVal){
            Node *inNode=new Node;  //Inserting inbetween a higher value and a lower value
            previous->next=inNode;
            inNode->next=temp;
            inNode->data = inVal;
        }
        //if (temp->next == nullptr &&count==length){
        else{
            temp->next = new Node; //if we are at the last node
            temp->next->data = inVal;
        }
    }
    length++;
}

int PQueue::remove(){
    Node* rem = first;
    first = first->next;
    int retVal = rem->data;
    delete rem;
    length--;
    return retVal;
}

bool PQueue::isInList(int inMnum){
    bool flag = true;
    Node* temp = first;
    while (flag){
        if (inMnum = temp->data){
            return true;
        }
    }
    return false;
}

bool PQueue::isEmpty(){
	if (first == nullptr){
		return true;
		}
	else { return false;}
}

int PQueue::getSize(){
    return length;}

void PQueue::printQueue(){
    cout<< "Priority Queue: "<<endl;
    Node *temp= first;
    while( temp!=nullptr){
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}