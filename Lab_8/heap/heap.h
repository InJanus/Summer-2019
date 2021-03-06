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
        heap();
        void insert(int);
        void remove();
        void printHeap();
        node* getNode(int);
};
