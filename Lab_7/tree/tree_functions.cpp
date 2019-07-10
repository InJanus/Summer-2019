#include "tree_balanced.h"
#include <iostream>
using namespace std;

string retval[100];
int count2;

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

void tree::rotateleft(node* pivot, node* parent){
    //root case
    if(parent == pivot){

    }
    node *temp = pivot ->right;
    pivot -> right -> left = pivot;
    pivot -> right -> right = nullptr;
    parent -> right = temp;
}

int h(node *parent){
    if (parent == nullptr){
        return 0;
    }else{
        int r = h(parent->right);
        int l = h(parent ->left);
        if(r>l){
            return r+1;
        }
        else{
            return l+1;
        }
    }

}

int tree::height(){
    return h(root);
}



void tree::print(){
    printNode(root, 0);
}

tree::tree(){
    size = 0;
    root = nullptr;
}

tree::~tree(){
    empty();
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

void tree::remove(string key){
    if(root == nullptr) throw "Empty tree Error";
    find(key); //handles the not in tree condition
    node *temp = root;
    node *temp2 = nullptr;
    
    while (temp->data != key){ //temp is node to remove
        temp2 = temp;	//temp2 is temp's parent
        if(key > temp->data){	
            temp = temp-> right;
        }
        else{
            temp = temp->left;
        }
    }
    //remove leaf
    if(temp->left ==  nullptr && temp->right == nullptr){ 
        if(temp2->data > temp->data) temp2->left = nullptr;
        else temp2->right = nullptr;
        delete temp;
        size--;
    }
    //remove with 1 child on left
    else if(temp->right == nullptr && temp->left != nullptr){ 
        if(temp2 == nullptr){    //if its root
            root = root->left;
        }else if(temp2->data > temp->data){
            temp2->left = temp->left;
        }
        else if(temp2->data < temp->data){
            temp2->right = temp->left;
        } 
        delete temp;
        size --;
    }
    //remove with 1 child on right
    else if(temp->left == nullptr && temp->right != nullptr){ 
        if(temp2 == nullptr){
            root = root->right;
        }else if(temp2->data > temp->data){
            temp2->right = temp->right; //
        }
        else if(temp2->data < temp->data){
            temp2->left = temp->right; //
        } 
        delete temp;
        size--;
    }
    // remove with 2 children
    else{ 
        bool flag = true;
        node* temp3 = temp;
        node* parent;
        parent = temp3;
        temp3 = temp3->right;//this has to check to see if noting exists in the right side
        while(temp3->left != nullptr){
            flag = false;
            parent = temp3;
            temp3 = temp3->left;
        }

        temp->data = temp3->data;
        if(flag){
            delete parent->right;
            parent->right = nullptr;
        }else{
            delete parent->left;
            parent->left = nullptr;
        }
    }
}

void deleteNode(node* temp){
    node* temp2 = temp;
    if(temp->right == nullptr && temp->left == nullptr){
        //do nothing
    }else if(temp->right == nullptr && temp->left != nullptr){
        deleteNode(temp->left);
    }else if(temp->right != nullptr && temp->left == nullptr){
        deleteNode(temp->right);
    }else{
        deleteNode(temp->right);
        deleteNode(temp->left);
    }
    delete temp2;
    temp2 = nullptr;
}

void tree::empty(){
    deleteNode(root);
    delete root;
    root = nullptr;
    size = 0;
}

string* getA(node* temp, string retval[]){
    if (temp->left) {
       getA(temp->left, retval);
    }
    retval[count2] = temp->data; // whatever it is you're storing
    count2++;
    if (temp->right) {
       getA(temp->right, retval);
    }
    return retval;
}

string* tree::getAllAcending(){
    for(int i = 0; i < 100; i++){
        retval[i] = "";
    }
    count2 = 0;
    return getA(root, retval);     //this is real close
}

string* getD(node* temp, string retval[]){
   if (temp->right) {
       getD(temp->right, retval);
   }
   retval[count2] = temp->data; // whatever it is you're storing
   count2++;
   if (temp->left) {
       getD(temp->left, retval);
   }
   return retval;
}

string* tree::getAllDecending(){
    for(int i = 0; i < 100; i++){
        retval[i] = "";
    }
    count2 = 0;
    return getD(root, retval);
}

