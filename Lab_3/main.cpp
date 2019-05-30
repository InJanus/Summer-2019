#include <iostream>
#include "linked_list.h"
using namespace std;

int main(){
    linked_list newclass;
    student dave;
    dave.firstName = "dave";
    dave.lastName = "butts";
    dave.gpa = 0.0;
    dave.m_number = 12345678;
    dave.birthday = "1-1-2000";
    dave.next = nullptr;
    newclass.addItem(dave);
}