#include <iostream>
#include <stdio.h>
#include <string.h>
#include "..\\Lab_3\linked_list\linked_list.h"
using namespace std;

void viewList(linked_list mylist){
    cout << "--------------------------------------------------------------------------" << endl;
    for(int i = 0; i < mylist.size(); i++){
        cout << "| " << i << " | ";
        int fnamel = mylist.seeAt(i).firstName.length();
        int fspace = (15-fnamel);
        cout << mylist.seeAt(i).firstName;
        for(int j = 0; j < fspace; j++){
            cout << " ";
        }
        cout << " | ";
        int lnamel = mylist.seeAt(i).lastName.length();
        int lspace = (20-lnamel);
        cout << mylist.seeAt(i).lastName;
        for(int j = 0; j < lspace; j++){
            cout << " ";
        }
        cout << " | ";
        cout << mylist.seeAt(i).birthday << " | " << mylist.seeAt(i).m_number << " | ";
        cout << mylist.seeAt(i).gpa;
        cout << endl;
    }
    cout << "--------------------------------------------------------------------------" << endl;
}


int main(){
    linked_list mylist;
    student input, temp;
    int search, test;
    bool stop = false;
    int choice;
    cout << "------------= Linked List Lab =------------" << endl;
    cout << "addItem --------------------------------- 1" << endl;
    cout << "getItem --------------------------------- 2" << endl;
    cout << "isinList -------------------------------- 3" << endl;
    cout << "isEmpty --------------------------------- 4" << endl;
    cout << "size ------------------------------------ 5" << endl;
    cout << "seeAt ----------------------------------- 6" << endl;
    cout << "seeNext --------------------------------- 7" << endl;
    cout << "reset ----------------------------------- 8" << endl;
    cout << "VIEW ITEMS ------------------------------ 9" << endl;
    cout << "exit ------------------------------------ 0" << endl;
    while(!stop){
        cout << "::> ";
        cin >> choice;

        switch (choice){
            case 1:
                //additem
                fflush(stdin);
                cout << "First Name: ";
                getline(cin, input.firstName);
                fflush(stdin);
                cout << "Last Name: ";
                getline(cin, input.lastName);
                fflush(stdin);
                cout << "M-Number: ";
                cin >> input.m_number;
                fflush(stdin);
                cout << "Birthday (mm/dd/yy): ";
                getline(cin, input.birthday);
                fflush(stdin);
                cout << "GPA: ";
                cin >> input.gpa;
                fflush(stdin);
                mylist.addItem(input);
                break;
            case 2:
                //getitem
                cout << endl << "Search by M-number: ";
                cin >> search;

                temp = mylist.getItem(mylist.isinList(search));
                cout << "FirstName: " << temp.firstName << endl;
                cout << "LastName: " << temp.lastName << endl;
                cout << "M-number: " << temp.m_number << endl; 
                cout << "Birthday: " << temp.birthday << endl;
                cout << "GPA: " << temp.gpa << endl << endl;
                break;
            case 3:
                //isinList
                cout << endl << "Search by M-number: ";
                cin >> search;
                if(mylist.isinList(search) == -1){
                    cout << "Not in list" << endl;
                }else{
                    cout << "Is in list" << endl;
                }
                break;
            case 4:
                //isempty
                if(mylist.isEmpty()){
                    cout << "list is empty" << endl;
                }else{
                    cout << "list is not empty" << endl;
                }
                break;
            case 5:
                cout << "size is: " << mylist.size() << endl;
                //size
                break;
            case 6:
                //seeAt
                cout << "location of student: ";
                cin >> search;
                temp = mylist.seeAt(search);
                cout << "FirstName: " << temp.firstName << endl;
                cout << "LastName: " << temp.lastName << endl;
                cout << "M-number: " << temp.m_number << endl; 
                cout << "Birthday: " << temp.birthday << endl;
                cout << "GPA: " << temp.gpa << endl << endl;
                break;
            case 7:
                //seeNext
                cout << "location of student: ";
                cin >> search;
                temp = mylist.seeNext(search);
                cout << "FirstName: " << temp.firstName << endl;
                cout << "LastName: " << temp.lastName << endl;
                cout << "M-number: " << temp.m_number << endl; 
                cout << "Birthday: " << temp.birthday << endl;
                cout << "GPA: " << temp.gpa << endl << endl;
                break;
            case 8:
                //reset
                mylist.reset();
                cout << "List reset" << endl;
                break;
            case 9:
                //VIEW
                viewList(mylist);
                break;
            case 0:
                //exit
                stop = true;
                break;
        }
    }
    return 0;
}