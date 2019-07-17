#include <string>
#include <list>
#include <vector>

using namespace std;

// struct node{
//     string data;
//     node* right = nullptr;
//     node* left = nullptr;
// };


    struct Node
    {
        Node* left;
        Node* right;
        string data;
    };

    /* 
        tree();                         //done         //constructer
        ~tree();                        //done        //destructer
        void insert(string);            
        node* find(string);             //done
        int getSize();                  //done
        string* getAllAcending();       //done
        string* getAllDecending();      //done
        void empty();                   //done
        void remove(string);            //need to add balance node and balace sides
        void print();                   //done
        int height();                   //done
        void balanceNodes();            //done
        void balanceTree();
        void balanceSides();
        */

class tree{
    public:

        tree(); //Done
        ~tree(); //Done
        void Insert(string input); //Done
        int Size(); //Done
        void Order(); //Done
        void Remove(string input); //May need work
        void remakeTree();
        void Test(vector<string> v_node, int start, int end);
        void printTree();

    private:
        //node* root;
        //int size;
        Node* Head;
	    int count2;
	    list<string> l_node;
	    void preOrder(Node* node);
};
