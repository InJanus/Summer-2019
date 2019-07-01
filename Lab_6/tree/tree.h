#include <string>
using namespace std;

struct node{
    string data;
    node* right = nullptr;
    node* left = nullptr;
};

class tree{

    private:
        node* root;
    public:
        tree(); //done         //constructer
        // ~tree();        //destructer
        void insert(string);            //done
        node* find(string);             //done
        int size();
        string* getAllAcending();
        string* getAllDecending();
        void empty();
        void remove(string);
        void print();                   //done
};