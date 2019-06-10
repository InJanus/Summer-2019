#include <string>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct student{
    int m_number;
    string firstName;
    string lastName;
    string birthday;
    double gpa;
    student *next = nullptr;
};

class linked_list2{
    private:
        int mylocation;
    public:
        student *head;
        linked_list2();
        void addItem(student, bool);
        student getItem(int);
        int isinList(int);
        bool isEmpty();
        int size();
        student seeNext();
        student seeAt(int);
        void reset();
};

#endif