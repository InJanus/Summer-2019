using namespace std;
#include <iostream>

struct node{
    int data;
    int index;
    node* next;
};

class graph{
    private:
        node* head;
        node* tail;
        int size;
    public:
        void addEdge(node i,node j);
        void removeEdge(node i,node j);
        bool hasEdge(node i,node j);
        string* outEdges(node i);
        string* inEdges(node j);

};