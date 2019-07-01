#include <string>
using namespace std;

struct node{
    string data;
    node* right;
    node* left;
};

class tree{

    private:
        node* root;
    public:
        tree();         //constructer
        ~tree();        //destructer
        void insert(string);
        node* find(string);
        int Size();
        string* getAllAcending();
        string* getAllDecending();
        void empty();
        void remove();
        void print();
        int size;
};