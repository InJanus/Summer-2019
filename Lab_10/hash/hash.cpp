#include <string>    //using
#include <iostream>  //using
#include <iomanip>   //using
#include <cstdio>    //FIXME i dont know if we are using this waste if we arent
#include <cstdlib>   //FIXME i dont know if we are using this waste if we arent
#include <random>    //using in creating random numbers for task 3
#include "hash.h"

using namespace std;
random_device rd;  // code for the random generator

//Both Constructors
HashTable::HashTable(){
    maxSize=100;
    arr = new string*[maxSize];
    for(int i = 0; i<maxSize; i++){
        arr[i] = nullptr;
    }
    size=0;
    conflicts=0;
}
HashTable::HashTable(int inVal/*,int numLetters_Hashs*/){
    maxSize =inVal;
    size=0;
    conflicts=0;
    //numLetters_Hash=numLetters_Hashs;
}
//Destructor
HashTable::~HashTable(){
    for(int i=0;i<=maxSize;i++){
        delete arr[i];
    }
}
//Hash Function, adds all the ASCII values in the string. FIXME put dis bitch in Private
int HashTable::Hash(string inVal){
    int retVal=0;
    for ( int i =0; i <inVal.length();i++){
        retVal += int(inVal.at(i));
    }
    return retVal;
}
int HashTable::Hash(string inVal,int numhash){
    int retVal=0;
    for ( int i =0; i <numhash;i++){
        retVal += int(inVal.at(i));
    }
    return retVal;
}
void HashTable::addItem(string inVal){
    if (size ==maxSize){
        cout<<" HashTable is full, Can not ADD"<<endl;
        return;
    }
    int key = Hash(inVal);
    key = key%maxSize;
    while(arr[key]!=nullptr){
        cout << arr[key] << endl;
        key++;
        key=key%maxSize;
        conflicts++;
    }
    arr[key]=new string;
    *arr[key]=inVal;
    size++;
}
void HashTable::addItem(string inVal,int numhash){
    if (size ==maxSize){
        cout<<" HashTable is full, Can not ADD"<<endl;
        return;
    }
    int key = Hash(inVal,numhash);
    key = key%maxSize;
    while(arr[key]!=nullptr){
        key++;
        key=key%maxSize;
        conflicts++;
    }
    arr[key]=new string;
    *arr[key]=inVal;
    size++;
}
void HashTable::print(){
    cout<<"Index"<<setw(8)<<"Value"<<setw(8)<<endl;
    for(int i=0;i<maxSize;i++){
        if(arr[i]!=nullptr){
            cout<<i<<setw(8)<<*arr[i]<<setw(8)<<endl;
        }
    }
}
string* HashTable::getItem(string inVal){
    int key = Hash(inVal);
    int ogKey=key;
    key=key%maxSize;
    //Checking for if value isnt there at all
    if(arr[key]==nullptr){
        cout<<"Not Found"<<endl;
        return nullptr;
    }
    //Loop for checking for duplicates
    while(*arr[key]==inVal && arr[(key+1)%maxSize]!=nullptr){
        ogKey= key;
        key++;
        key=key%maxSize;
    }
    //Finding the value and if duplicates, will remove the duplicate added last
    if(*arr[key]==inVal){
        cout<<"Value found in HashTable "<<endl;
        cout<<"Index value: "<<key<<endl;
        return arr[key]; 
    }
}
string HashTable::RemoveItem(string inVal){
    string retVal;
    string* delnode=getItem(inVal);
    int key = Hash(inVal);
    if(delnode==nullptr || size ==0){
        cout<<"Can Not Delete"<<endl;
        return ""; //[FIXME] I think its supposed to return nullptr but like idk
    }
    retVal = *delnode;
    delete arr[key%maxSize];
    arr[key%maxSize] = nullptr;
    size--;
    return retVal;
}
int HashTable::getLength(){
    return size;
}
int HashTable::getCollisions(){
    return conflicts;
}
int HashTable::getMaxSize(){
    return maxSize;
}
string HashTable::randStringCreate(){
    //srand(time(NULL)); //NOT USING BECAUSE IT DOES NOT REFRESH FAST ENOUGH. ITS NO GOOD
    string out;               
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(65,122);// FIXME maybe fix becuase it seeds the same everytime, possibly fix
    for( int i=0;i<4;i++){
        out +=char(dist(mt));
    }
    return out;
}



























// HashMapTable::HashMapTable() {
// 	ht = new HashTable * [TableSIze];
// 	for (int i = 0; i < TableSIze; i++) {
// 		ht[i] = NULL;
// 	}
// }

// }
// void HashMapTable::addItem(int k, int v) {
// 	int hash_val = Hash(k);
// 	int init = -1;
// 	int delindex = -1;
// 	while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
// 		if (init == -1)
// 			init = hash_val;
// 		if (ht[hash_val] == DelNode::getNode())
// 			delindex = hash_val;
// 		hash_val = Hash(hash_val + 1);
// 	}
// 	if (ht[hash_val] == NULL || hash_val == init) {
// 		if (delindex != -1)
// 			ht[delindex] = new HashTable(k, v);
// 		else
// 			ht[hash_val] = new HashTable(k, v);
// 	}
// 	if (init != hash_val) {
// 		if (ht[hash_val] != DelNode::getNode()) {
// 			if (ht[hash_val] != NULL) {
// 				if (ht[hash_val]->k == k)
// 					ht[hash_val]->v = v;
// 			}
// 		}
// 		else
// 			ht[hash_val] = new HashTable(k, v);
// 	}
// }
// int HashMapTable::getItem(int k) {
// 	int hash_val = Hash(k);
// 	int init = -1;
// 	while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
// 		if (init == -1)
// 			init = hash_val;
// 		hash_val = Hash(hash_val + 1);
// 	}
// 	if (ht[hash_val] == NULL || hash_val == init)
// 		return -1;
// 	else
// 		return ht[hash_val]->v;
// }
// void HashMapTable::RemoveItem(int k) {
// 	int hash_val = Hash(k);
// 	int init = -1;
// 	while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
// 		if (init == -1)
// 			init = hash_val;
// 		hash_val = Hash(hash_val + 1);
// 	}
// 	if (hash_val != init && ht[hash_val] != NULL) {
// 		delete ht[hash_val];
// 		ht[hash_val] = DelNode::getNode();
// 	}
// }
// HashMapTable::~HashMapTable() {
// 	delete[] ht;
// }
// DelNode* DelNode::en = NULL;

