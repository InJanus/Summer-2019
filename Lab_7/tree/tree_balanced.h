#include <string>
#include <list>
#include <vector>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    string data;
};

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
        Node* Head;
	    int count2;
	    list<string> l_node;
	    void preOrder(Node* node);
};
