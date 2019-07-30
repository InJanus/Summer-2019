#include "pqueue.h"
#include <iostream>
using namespace std;

void PQueue::insert(int inVal) {             //FIXME need to do it so that the insert is in the right place 
	Node* temp, * temp2;
	temp = new Node;
	temp->data = inVal;
	if (first == NULL) {
		temp->next = first;
		first = temp;
	}
	else {
		temp2 = first;
		while (temp2->next != NULL && temp2->next->data >= inVal)
			temp2 = temp2->next;
		temp->next = temp2->next;
		temp2->next = temp;
	}
	length++;
}

int PQueue::remove() {
	Node* temp;
	if (first == NULL) //if queue is null
		cout << "Queue Underflow\n";
	else {
		temp = first;
		//cout << "Deleted item is: " << temp->data << endl;
		first = first->next;
		int value = temp->data;
		free(temp);
		return value;
		}
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