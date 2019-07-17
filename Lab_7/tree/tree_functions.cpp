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

void rotateleft(node* pivot, node* parent){
    //root case
    node* temp = nullptr;
    if(parent == pivot){
        node* temp2 = new node;
        temp2->data = parent->data;
        parent->data = parent->right->data;
        parent->right->data = parent->right->right->data;
        parent->right->right = nullptr;
        parent->left = temp2;
    }else if(pivot->right->left == nullptr){
        parent->right = parent->right->right;
        pivot->right->left = pivot;
        pivot->right = temp;
    }else{
        parent->right = parent->right->right;
        pivot->right->right = pivot;
        pivot->right = temp;
    }
}

void rotateright(node* pivot, node* parent){
    node* temp = nullptr;
    if(parent == pivot){
        node* temp2 = new node;
        temp2->data = parent->data;
        parent->data = parent->left->data;
        parent->left->data = parent->left->left->data;
        parent->left->left = nullptr;
        parent->right = temp2;
    }else if(parent->left == pivot){
        parent->left = parent->left->left;
        pivot->left->left = pivot;
        pivot->left = temp;
    }else{
        parent->left = parent->left->left;
        pivot->left->right = pivot;
        pivot->left = temp;
    }
}

void tree_left(node* subRoot)
{
	if (subRoot == NULL || subRoot->right == NULL)
		cout << "WARNING: program error detected in rotate_left" << endl;
	else {
		node* right_tree = subRoot->right;
		subRoot->right = right_tree->left;
		right_tree->left = subRoot;
		subRoot = right_tree;
	}
}
void tree_right(node* subRoot)
{
	if (subRoot == NULL || subRoot->left == NULL)
		cout << "WARNING: program error detected in rotate_left" << endl;
	else {
		node* left_tree = subRoot->left;
		subRoot->left = left_tree->right;
		left_tree->right = subRoot;
		subRoot = left_tree;
	}
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

void rightTree(node* root)
{
	int heightRight = h(root->right);
	int heightLeft = h(root->left);
	node* right_tree = root->right;
	if (heightRight - heightLeft == 2) {
		if (heightRight > heightLeft) {
			tree_left(root);
		}
		else {

		}
		tree_right(right_tree);
		tree_left(root);
	}
}
void leftTree(node* root)
{
	int heightRight = h(root->right);
	int heightLeft = h(root->left);
	node* left_tree = root->left;
	if (heightRight - heightLeft == 2) {
		if (heightRight < heightLeft) {
			tree_right(root);
		}
		else {

		}
		tree_left(left_tree);
		tree_right(root);
	}
}

void nodesBalance(node* parent, node* child, node* root){
    int heightRight = h(child->right);
    int heightLeft = h(child->left);
    if(abs(heightRight-heightLeft)==2){
        if(heightRight > heightLeft){
            if(heightLeft == 0){
                rotateleft(child, parent);
            }else{
                nodesBalance(child ,child->right, root);
            }
        }else{
            if(heightRight==0){
                rotateright(child, parent);
            }else{
                nodesBalance(child, child->left, root);
            }
        }
    }
}

void tree::balanceNodes(){
    nodesBalance(root, root, root);
}

void tree::balanceTree() {
	treeBalance(root);

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
    balanceTree();
    balanceNodes();
    
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
    balanceNodes();
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

