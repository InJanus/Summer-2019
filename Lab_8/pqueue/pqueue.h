using namespace std;
#include <iostream>


struct Node
{
	int data;
	Node *next = nullptr;

};

class PQueue
{
private:
    int length = 0; //increment and decrement as necessary
public:
	Node *first = nullptr;

    void insert(int inNum); //[FIXME] FIX DIS BITCH
    int remove(); //Done
    bool isInList(int inMnum); //Done
    bool isEmpty(); //Done
    int getSize(); //Done
    void print();
};

