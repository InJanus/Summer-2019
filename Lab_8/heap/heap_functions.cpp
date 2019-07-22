#include "heap.h"
#include<iostream>
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

void heap::insert(int node){
    if (head == nullptr){
        head =new Node;
        head->data = node;
    }
    else{
        tail -> next = new Node;
        tail -> next -> data = node;
        tail -> node;
    }
}
//for remove we have to look at the children and replace with the greater child and continue to do that.


//heap up 