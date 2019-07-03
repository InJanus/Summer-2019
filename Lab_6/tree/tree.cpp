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
    printNode(root, 0);
}

tree::tree(){
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
    //remove leaf
    if(temp->left ==  nullptr && temp->right == nullptr){ 
        if(temp2->data > temp->data) temp2->left = nullptr;
        else temp2->right = nullptr;
        delete temp;
        size--;
    }
    //remove with 1 child on left
    else if(temp->right == nullptr && temp->left != nullptr){ 
        if(temp2->data > temp->data){
            temp2->left = temp->left;
        }
        else{
            temp2->right = temp->left;
        }
        delete temp;
        size --;
    }
    //remove with 1 child on right
    else if(temp->left == nullptr && temp->right != nullptr){ 
        if(temp2->data > temp->data){
            temp2->right = temp->right; //
        }
        else{
            temp2->left = temp->right; //
        }
        delete temp;
        size--;
    }
    // remove with 2 children
    else{ 
        node *temp3 = root;
        temp3 = temp3 -> left;
        while (temp3 -> right != nullptr){
            temp3 = temp3 -> right;
        }
        node *replace = temp3; //replace
        replace->left = temp->left;
        replace->right = temp->right;
        if(temp2->data > replace->data){
            temp2->left = replace;
        } 
        else {
            temp2->right = replace;
        }
        delete temp3;
    }
    //still need to handle removing root;
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

string* getA(node* temp, string retval[], int count){
    if(temp == nullptr){
        return new string[1];
    }
    getA(temp->left, retval, count);
    getA(temp->right, retval, count);
    retval[count] = temp->data;
    count++;

}

string* tree::getAllAcending(node* temp, string myarray[],int count){
    // string* temp = getLetter(root, 0);
    // for(int i = 0; i < size; i++){
    //     cout << temp[i] << endl;
    // }
   if (temp->left) {
    getAllAcending(temp->left, myarray, count);
   }
   count++;
   myarray[count] = temp->data; // whatever it is you're storing
   if (temp->right) {
    getAllAcending(temp->right, myarray, count);
   }

   return myarray;
}
    //string* retval = new string[size];

    //return getA(root, retval, 0);
    // node* temp = root;
    // node* temp2;
    // node* retval[size];

    // for(int i = 0; i < size; i++){
    //     temp = root;
    //     while(temp->left != nullptr){
    //         temp2 = temp;
    //         temp = temp->left;
    //     }
    //     if()
    //     retval[i] = temp;

    // }

    //int ammountSorted = 0;

    // while(ammountSorted < size){
    //     for(int i = 0; i < size-ammountSorted-1; i++){
    //         if(retval[i+1].compare(retval[i]) < 1){
    //             //switch the items
    //             int temp2 = temp[i];
    //             temp[i] = temp[i+1];
    //             temp[i+1] = temp2;
    //         }
    //     }
    //     ammountSorted++;
    // }
    // return retval;
    //works
//}
