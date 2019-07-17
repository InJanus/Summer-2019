#include <string>
#include <list>
#include <vector>

using namespace std;

struct node{
    string data;
    node* right = nullptr;
    node* left = nullptr;
};

class tree{
    public:
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
    struct Node
        {
            Node* left;
            Node* right;
            int data;
        };
	tree(); //Done
	~tree(); //Done
	void Insert(int input); //Done
	int Size(); //Done
	void Order(); //Done
	void Remove(int input); //May need work
	void remakeTree();
	void Test(vector<int> v_node, int start, int end);

    private:
        //node* root;
        //int size;
        Node* Head;
	    int count2;
	    list<int> l_node;
	    void preOrder(Node* node);
};
