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
        void insert(string);            //done
        node* find(string);             //done
        int getSize();                  //done
        string* getAllAcending(node* temp, string myarray[],int count);       
        string* getAllDecending();
        void empty();                   //done
        void remove(string);            
        void print();                   //done
};