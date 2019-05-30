#include <iostream>
#include "..\\Lab_3\linked_list\linked_list.h"
using namespace std;

int main(){
    linked_list newclass;
    student dave;
    student temp;
    dave.firstName = "dave";
    dave.lastName = "butts";
    dave.gpa = 0.0;
    dave.m_number = 12345678;
    dave.birthday = "1-1-2000";
    dave.next = nullptr;
    newclass.addItem(dave);
    newclass.addItem(dave);
    newclass.addItem(dave);
    temp = newclass.getItem(0);
    cout << temp.firstName << endl;

}