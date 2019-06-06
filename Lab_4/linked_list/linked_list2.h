#include <string>
using namespace std;

struct student{
    int m_number;
    string firstName;
    string lastName;
    string birthday;
    double gpa;
    student *next = nullptr;
};

class linked_list{
    private:
        student *head;
        student *pointer;
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