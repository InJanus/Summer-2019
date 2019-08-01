using namespace std;
#include <iostream>

class hash{
    private:
        int size;
        int hashfunction(string);
        
    public:
        hash();
        ~hash();
        void addItem(string item);
        string returnItem(string item);
        string* getItem();
        int getLength();
        };