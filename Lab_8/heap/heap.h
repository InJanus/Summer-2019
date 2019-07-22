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
        int size;
    public:
        void insert(int);
        void remove(int);
        void printHeap();
};
