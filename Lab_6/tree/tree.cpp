#include "tree.h"
using namespace std;

void tree::print(){
    string mytemp;
}
class node{
	int data;
	node *right, *left;
};

class tree{
    
	int Find(int key){
		node *temp = root;
		while(temp != nullptr && temp->data != key){
			if(key > temp->data){
				temp = temp-> right;
			}
			else{
				temp = temp->left;
			}
		}
		if(temp == nullptr) throw "Not Found!";
		return temp->data;
	}
	
	int FindR(int key, node *t = root){
		if(t == nullptr) throw "Not Found!");
		if(t->data == key) return t->data;
		if(t->data < key) return FindR(key, t->right);
		return FindR(key, t->left);
	}
	
	void Add(int key){
		node *temp = root;
		node *temp2;
		if(temp == nullptr){
			root = new node;
			root->data = key;
			return;
		}		
		while (temp != nullptr){
			temp2 = temp;
			if(key > temp->data){	
				temp = temp-> right;
			}
			else{
				temp = temp->left;
			}
		}
		if(temp2->data > key){
			temp2->left = new node;
			temp2->left->data = key;
		}
		else{
			temp2->right = new node;
			temp2->right->data = key;
		}
	}
	
	void Delete(int key){
		if(root == nullptr) throw "Empty tree Error";
		Find(key); //handles the not in tree condition
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
			node *replace = GetLagestSmaller(temp);
			replace->left = temp->left;
			replace->right = temp->right;
			if(temp2->data > replace->data) temp2-left = replace;
			else temp2->right = replace;
			delete temp;
		}
		//still need to handle removing root;
	}