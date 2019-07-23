#include "heap.h"
#include <iostream>
#include <math.h>
using namespace std;

int parent(int index) { 
    return floor(index-1)/2; 
} 
  
// to get index of left child of node at index i 
int left(int index) { 
    return (2*index + 1); 
} 

// to get index of right child of node at index i 
int right(int index) { 
    return (2*index + 2); 
}

heap::heap(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void heap::insert(int inVal){
    if (head == nullptr){
        head = new node;
        head->data = inVal;
        head -> index = 0;
        tail = head;
        size++;
    }
    else{
        tail -> next = new node;
        tail = tail->next;
        tail -> data = inVal;
        size++;
        tail -> index = size;
        tail -> next = nullptr;

        // This swaps it up. So if the parent is larger... it'll swap the parent with the child.  
        int parentIndex = tail -> index;
        while(getNode(parentIndex) -> data > getNode(parent(parentIndex)) -> data){
            int temp = getNode(parentIndex) -> data;
            getNode(parentIndex) -> data = getNode(parent(parentIndex)) -> data;
            getNode(parent(parentIndex)) -> data = temp;
            parentIndex = parent(parentIndex);
        }    
    }

}
void heap::printHeap(){
    //this just prints the array/linked list for the heap
    node* temp = head;
    while(temp != nullptr){
        cout << "index:" << temp->index << " -- " << temp->data << endl;
        temp = temp->next;
    }
}

node* heap::getNode(int index){
    node* temp = head;
    for(int i = 0; i < index - 1; i++){
        temp = temp->next;
    }
    return temp;
}

void heap::remove(/* int getdata*/){
    // //this has to search first then delete the found data
    // int tempindex = -1;
    // node* temp = head;
    // node* prevnode;
    // //find the removing node
    // while(temp != nullptr){
    //     prevnode = temp;
    //     if(temp->data == getdata){
    //         tempindex = temp->index;
    //     }
    //     temp = temp->next;
    // }
    
    // if(tempindex != -1){
    //     //number exists
    //     node* myleft = getNode(left(tempindex));
    //     node* myright = getNode(right(tempindex));

    //     if((myleft == nullptr)&&(myright == nullptr)){   //no children
    //         prevnode->next = prevnode->next->next;
    //         delete temp;
    //     }//else if((myleft != nullptr)&&(myright == nullptr)){ //left child no right

    //     //}//else if((myleft == nullptr)&&(myright != nullptr)){ // right child no left
            
    //     //}//else if((myleft != nullptr)&&(myright != nullptr)){ // shit... two children
            
    //     //}
    // }
    node* temp = head;
    node * prev;
    while(temp != nullptr){
        prev = temp;
        temp = temp->next;
    }
    tail = prev;
    temp = nullptr;
    delete temp;
    
}


//for remove we have to look at the children and replace with the greater child and continue to do that.


//heap up 