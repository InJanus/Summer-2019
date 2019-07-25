#include <string>
using namespace std;

struct bigdata{
    string name;
    bigdata *next = nullptr;
};

class linked_list{
    private:
        bigdata *head;
        int mylocation;
    public:
        linked_list();
        void addItem(bigdata);
        bigdata getItem(int);
        int isinList(string);
        bool isEmpty();
        int size();
        bigdata seeNext();
        bigdata seeAt(int);
        void reset();
};