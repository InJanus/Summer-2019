#include <string>
using namespace std;

struct student{
    int m_number;
    string firstName;
    string lastName;
    string birthday;
    int gpa;
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
        bool isinList(student);
        bool isEmpty();
        int size();
        student seeNext(int);
        student seeAt(int);
        void reset();
};