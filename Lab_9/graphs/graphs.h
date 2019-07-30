using namespace std;
#include <iostream>
#include "..\linked_list\linked_list.h"

struct node{
    linked_list data;
    string name;
    node* next = nullptr;
};

class graph{
    private:
        node* head;
        int size;
        // Something establising a list
    public:
        graph();
        ~graph();
        void addEdge(string ,linked_list );
        void removeEdge(string ,linked_list);
        bool hasEdge(string ,string);
        linked_list outEdges(string);
        linked_list inEdges(string);
        void printGraph();

};