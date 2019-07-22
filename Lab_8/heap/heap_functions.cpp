#include "heap.h"
#include <iostream>
#include <math.h>
using namespace std;

int parent(int node) { 
    return floor(node-1)/2; 
} 
  
// to get index of left child of node at index i 
int left(int node) { 
    return (2*node + 1); 
} 
  
// to get index of right child of node at index i 
int right(int node) { 
    return (2*node + 2); 
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
    for(int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp;
}

void heap::remove(int getdata){
    //this has to search first then delete the found data
    int tempindex = -1;
    node* temp = head;
    node* prevnode;
    //find the removing node
    while(temp != nullptr){
        prevnode = temp;
        if(temp->data == getdata){
            tempindex = temp->index;
        }
        temp = temp->next;
    }
    
    if(tempindex != -1){
        //number exists
        node* myleft = getNode(left(tempindex));
        node* myright = getNode(right(tempindex));

        if((myleft == nullptr)&&(myright == nullptr)){   //no children
            prevnode->next = prevnode->next->next;
            delete temp;
        }else if((myleft != nullptr)&&(myright == nullptr)){

        }else if((myleft == nullptr)&&(myright != nullptr)){
            
        }else if((myleft != nullptr)&&(myright != nullptr)){
            
        }
    }

    



}


//for remove we have to look at the children and replace with the greater child and continue to do that.

//heap up 