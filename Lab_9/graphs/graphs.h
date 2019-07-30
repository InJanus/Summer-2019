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
        void removeEdge(string i,linked_list j);
        bool hasEdge(string i,string j);
        string outEdges(node i);
        string inEdges(node j);
        void printGraph();

};