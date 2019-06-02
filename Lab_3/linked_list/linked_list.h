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
    public:
        linked_list();
        void addItem(student);
        student getItem(int);
        int isinList(student);
        bool isEmpty();
        int size();
        //student seeNext();
        //student seeAt(int);
        //void reset();
};