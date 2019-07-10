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
        int size;
    public:
        tree();                         //done         //constructer
        ~tree();                        //done        //destructer
        void insert(string);            
        node* find(string);             //done
        int getSize();                  //done
        string* getAllAcending();       //done
        string* getAllDecending();      //done
        void empty();                   //done
        void remove(string);            
        void print();                   
        void rotateleft(node* pivot, node* parent);
        int height(node *parent);
};