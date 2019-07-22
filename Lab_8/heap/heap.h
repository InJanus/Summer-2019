using namespace std;
#include <iostream>

struct node{
    int data;
    int index;
    node* next;
};

class heap{
    private:
        node* head;
        node* tail;
        int size;
    public:
        void insert(int);
        void remove(int);
        void printHeap();
        node* getNode(int);
};
