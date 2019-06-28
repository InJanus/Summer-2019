#include <string>
using namespace std;

class tree{

    private:
        string data;
        tree* right;
        tree* left;
    public:
        tree();         //constructer
        ~tree();        //destructer
        void insert(string);
        bool find(string);
        int size();
        string* getAllAcending();
        string* getAllDecending();
        void empty();
        void remove();
        void print();
};