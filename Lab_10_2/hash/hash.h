#include <iostream>
#include <cstdio>
#include <cstdlib>
#include ".\\Lab_10_2\linked_list\linked_list.h"

using namespace std;


struct team{
	string name;
	linked_list resultyears;
	bool operator==(team &);
	void operator=(team &);
};

class HashTable{
	private:
		int maxSize;
		team** arr; //dynamically sized array of pointers for strings
		int size;
		int conflicts;
	public:
		HashTable(); //Done
		HashTable(int); //Done
		int Hash(team); //Done
		void print();//Done
		void addItem(team); //Done [Might need some error checking]
		team RemoveItem(team);
		team* getItem(team);
		int getCollisions();
		int getMaxSize();
		int getLength();
		~HashTable();
		string randStringCreate();
};