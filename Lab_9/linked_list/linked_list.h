#include <string>
using namespace std;

struct state{
    
};

class linked_list{
    private:
        node *head;
        int mylocation;
    public:
        linked_list();
        void addItem(student);
        student getItem(int);
        int isinList(int);
        bool isEmpty();
        int size();
        student seeNext();
        student seeAt(int);
        void reset();
};