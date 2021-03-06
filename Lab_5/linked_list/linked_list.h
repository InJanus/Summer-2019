#include <string>
using namespace std;

#ifndef LINKED_LIST
#define LINKED_LIST

struct student{
    int m_number;
    string firstName;
    string lastName;
    string birthday;
    double gpa;
    student *next = nullptr;
    student *prev = nullptr;
};

class linked_list{
    private:
        student *head;
        int mylocation;
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
        void bubbleSort();
        void radixSort();
        void insertionSort();
        void radix_flip();
        void bubble_flip();
        void insertion_flip();
};

#endif