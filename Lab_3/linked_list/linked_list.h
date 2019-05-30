#include <string>
using namespace std;

struct student{
    int m_number;
    string firstName;
    string lastName;
    string birthday;
    int gpa;
    student *next;
};

class linked_list{
    private:
        student *head;
    public:
        void addItem(student);
        student getItem();
        bool isinList(student);
        bool isEmpty();
        int size();
        student seeNext();
        student seeAt(int);
        void reset();
};