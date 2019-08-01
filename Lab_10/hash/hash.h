using namespace std;
#include <iostream>

class hash{
    private:
        int size;
        
    public:
        hash();
        ~hash();
        void addItem(string item);
        string returnItem(string item);
        int* getItem();
};