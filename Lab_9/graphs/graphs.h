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
        // Something establising a list
    public:
        graph();
        ~graph();
        void addEdge(node i,node j);
        void removeEdge(node i,node j);
        bool hasEdge(node i,node j);
        string outEdges(node i);
        string inEdges(node j);
        void printGraph();

};