#include <iostream>
#include <cstdio>
#include <cstdlib>
//const int TableSIze = 100;
using namespace std;


class HashTable{
	private:
		int maxSize;
		string** arr; //dynamically sized array of pointers for strings
		int size;
		int conflicts;
	public:
		HashTable(); //Done
		HashTable(int); //Done
		int Hash(string); //Done
		int Hash(string, int); //For Task 3
		void print();//Done
		void addItem(string); //Done [Might need some error checking]
		void addItem(string,int); //For Task 3
		string RemoveItem(string);
		string* getItem(string);
		int getCollisions();
		int getMaxSize();
		int getLength();
		~HashTable();
		string randStringCreate();
};

// class HashTable {
// public:
// 	int k;
// 	int v;
// 	HashTable(int k, int v) {
// 		this->k = k;
// 		this->v = v;
// 	}
// };

// class DelNode :public HashTable {
// private:
// 	static DelNode* en;
// 	DelNode() :HashTable(-1, -1) {}
// public:
// 	static DelNode* getNode() {
// 		if (en == NULL)
// 			en = new DelNode();
// 		return en;
// 	}
// };


// class HashMapTable {
// private:
// 	HashTable** ht;
// public:
// 	HashMapTable();
// 	int Hash(string);
// 	void addItem(int, int);
// 	int getItem(int);
// 	void RemoveItem(int);
// 	~HashMapTable();
// };

// class HashMapTable {
// private:
// 	HashTable** ht;
// public:
// 	HashMapTable();
// 	int Hash(string);
// 	void addItem(int, int);
// 	int getItem(int);
// 	void RemoveItem(int);
// 	~HashMapTable();
// };