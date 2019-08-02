#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
const int T_S = 100;
using namespace std;


class HashTable {
public:
	int k;
	int v;
	HashTable(int k, int v) {
		this->k = k;
		this->v = v;
	}
};

class DelNode :public HashTable {
private:
	static DelNode* en;
	DelNode() :HashTable(-1, -1) {}
public:
	static DelNode* getNode() {
		if (en == NULL)
			en = new DelNode();
		return en;
	}
};


class HashMapTable {
private:
	HashTable** ht;
public:
	HashMapTable();
	int Hash(int);
	void addItem(int, int);
	int getItem(int);
	void RemoveItem(int);
	~HashMapTable();
};
