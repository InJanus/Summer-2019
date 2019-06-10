#include "..\\linked_list\linked_list2.h"

#ifndef CLASSES_H
#define CLASSES_H

class classes:linked_list2{
    private:
        int mysize;  

    public:
        classes();
        classes(int);
        void addItem(student);
        student getItem();
        bool isEmpty();
        bool isFull();
        int size();
        void clearList();
        int getMaxSize();
};

#endif