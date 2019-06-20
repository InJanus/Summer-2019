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
        void bubbleSort_mn();
        void bubbleSort_fn();
        void bubbleSort_ln();
        void radixSort();
        void insertionSort_mn();
        void insertionSort_fn();
        void insertionSort_ln();
        void radix_flip();
        void bubble_flip_mn();
        void bubble_flip_fn();
        void bubble_flip_ln();
        void insertion_flip_mn();
        void insertion_flip_fn();
        void insertion_flip_ln();
};

#endif