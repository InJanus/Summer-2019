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
        void addItem(string);
        bigdata getItem(int);
        int isinList(string);
        bool isEmpty();
        int size();
        bigdata seeNext();
        bigdata seeAt(int);
        void reset();
        void removeAll();
        bool equalto(linked_list);
};