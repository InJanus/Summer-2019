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


//for remove we have to look at the children and replace with the greater child and continue to do that.

//heap up 