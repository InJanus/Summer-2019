#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "hash.h"

using namespace std;


HashMapTable::HashMapTable() {
	ht = new HashTable * [T_S];
	for (int i = 0; i < T_S; i++) {
		ht[i] = NULL;
	}
}
int HashMapTable::Hash(string inVal){
    int retVal;
    for ( int i =0; i <inVal.length();i++){
        retVal += int(inVal.at(i));
    }
    return retVal;
}
void HashMapTable::addItem(int k, int v) {
	int hash_val = Hash(k);
	int init = -1;
	int delindex = -1;
	while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
		if (init == -1)
			init = hash_val;
		if (ht[hash_val] == DelNode::getNode())
			delindex = hash_val;
		hash_val = Hash(hash_val + 1);
	}
	if (ht[hash_val] == NULL || hash_val == init) {
		if (delindex != -1)
			ht[delindex] = new HashTable(k, v);
		else
			ht[hash_val] = new HashTable(k, v);
	}
	if (init != hash_val) {
		if (ht[hash_val] != DelNode::getNode()) {
			if (ht[hash_val] != NULL) {
				if (ht[hash_val]->k == k)
					ht[hash_val]->v = v;
			}
		}
		else
			ht[hash_val] = new HashTable(k, v);
	}
}
int HashMapTable::getItem(int k) {
	int hash_val = Hash(k);
	int init = -1;
	while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
		if (init == -1)
			init = hash_val;
		hash_val = Hash(hash_val + 1);
	}
	if (ht[hash_val] == NULL || hash_val == init)
		return -1;
	else
		return ht[hash_val]->v;
}
void HashMapTable::RemoveItem(int k) {
	int hash_val = Hash(k);
	int init = -1;
	while (hash_val != init && (ht[hash_val] == DelNode::getNode() || ht[hash_val] != NULL && ht[hash_val]->k != k)) {
		if (init == -1)
			init = hash_val;
		hash_val = Hash(hash_val + 1);
	}
	if (hash_val != init && ht[hash_val] != NULL) {
		delete ht[hash_val];
		ht[hash_val] = DelNode::getNode();
	}
}
HashMapTable::~HashMapTable() {
	delete[] ht;
}
DelNode* DelNode::en = NULL;

