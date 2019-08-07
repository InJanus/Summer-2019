#include <string>
using namespace std;

struct game{
    int year;
    bool result;
    game* next = nullptr;
};

class linked_list{
    private:
        game *head;
        int mylocation;
    public:
        linked_list();
        void addItem(game);
        game getItem(int);
        int isinList(int);
        bool isEmpty();
        int size();
        game seeNext();
        game seeAt(int);
        void reset();
        bool isEqual(linked_list);
        void removeAll();
};