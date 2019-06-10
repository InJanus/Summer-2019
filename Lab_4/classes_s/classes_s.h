#include "..\\linked_list\linked_list2.h"

#ifndef CLASSES_S_H
#define CLASSES_S_H

class classes_s:linked_list2{
    private:
        int mysize;  

    public:
        classes_s();
        classes_s(int);
        void addItem(student);
        student getItem();
        bool isEmpty();
        bool isFull();
        int size();
        void clearList();
        int getMaxSize();
};

#endif