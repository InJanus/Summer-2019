#include "tree.h"
#include <iostream>
using namespace std;

void printNode(node* temp, int level){
    if(temp->right == nullptr && temp->left == nullptr){
        cout << "level: " << level << " -- " << temp->data << endl;
    }else if(temp->right == nullptr && temp->left != nullptr){
        printNode(temp->left, level+1);
        cout << "level: " << level << " -- " << temp->data << endl;
    }else if(temp->right != nullptr && temp->left == nullptr){
        printNode(temp->right, level+1);
        cout << "level: " << level << " -- " << temp->data << endl;
    }else{
        printNode(temp->right, level+1);
        printNode(temp->left, level+1);
        cout << "level: " << level << " -- " << temp->data << endl;
    }
}

void tree::print(){
    node* temp = root;
    printNode(temp, 0);
}

tree::tree(){
    root = nullptr;
}


node* tree::find(string key){
    node *temp = root;
    while(temp != nullptr && temp->data.compare(key) != 0){
        if(temp->data.compare(key) < 1){ //test to see if correct
            temp = temp-> right;
        }
        else{
            temp = temp->left;
        }
    }
    if(temp == nullptr){
        cout << "node not found" << endl;
    }// throw "Not Found!";
    return temp;
}

void tree::insert(string key){
    node *temp = root;
    node *temp2;
    if(temp == nullptr){
        root = new node;
        root->data = key;
        size++;
        return;
    }		
    while (temp != nullptr){
        temp2 = temp;
        if(temp->data.compare(key) < 1){	
            temp = temp-> right;
        }
        else{
            temp = temp->left;
        }
    }
    if(temp2->data.compare(key) == 1){
        temp2->left = new node;
        temp2->left->data = key;
        size++;
    }
    else{
        temp2->right = new node;
        temp2->right->data = key;
        size++;
    }
}

int tree::getSize(){
    return size;
}

// DONT FORGET TO SUBTRACT SIZE <-------------------------------------------------------------------
void tree::remove(string key){
    if(root == nullptr) throw "Empty tree Error";
    find(key); //handles the not in tree condition
    node *temp = root;
    node *temp2;
    
    while (temp->data != key){ //temp is node to remove
        temp2 = temp;	//temp2 is temp's parent
        if(key > temp->data){	
            temp = temp-> right;
        }
        else{
            temp = temp->left;
        }
    }
    if(temp->left ==  nullptr && temp->right == nullptr){ //remove leaf
        if(temp2->data > temp->data) temp2->left = nullptr;
        else temp2->right = nullptr;
        delete temp;
    }
    else if(temp->right == nullptr && temp->left != nullptr){ //remove with 1 child on left
        if(temp2->data > temp->data){
            temp2->left = temp->left;
        }
        else{
            temp2->right = temp->left;
        }
        delete temp;
    }
    else if(temp->right == nullptr && temp->left != nullptr){ //remove with 1 child on right
        if(temp2->data > temp->data){
            temp2->left = temp->left; //may need to fix
        }
        else{
            temp2->right = temp->left; //may need to fix
        }
        delete temp;
    }
    else{ // remove with 2 children
        node *replace = GetLagestSmaller(temp); //replace
        replace->left = temp->left;
        replace->right = temp->right;
        if(temp2->data > replace->data) temp2->left = replace;
        else temp2->right = replace;
        delete temp;
    }
    //still need to handle removing root;
}