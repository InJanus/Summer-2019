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