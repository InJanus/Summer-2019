#include <iostream>
#include "..\\Lab_4\classes\classes.h"
#include "..\\Lab_4\classes_s\classes_s.h"
using namespace std;

int main(){
    //main for classes.cpp
    //evently there will be one for stack and queue as well but in linked list versions

    bool stop = false;
    int choice, choice2;
    bool testing;
    int testing2;

    cout << "Enter size of list: ";
    cin >> choice;
    
    classes myinput(choice);
    classes_s myinput2(choice);
    cout << "queue(1) or stack(2): ";
    cin >> choice2;

    student input, temp;

    cout << "addItem ---------------------------- 1" << endl;
    cout << "getItem ---------------------------- 2" << endl;
    cout << "isEmpty ---------------------------- 3" << endl;
    cout << "isFull ----------------------------- 4" << endl;
    cout << "size ------------------------------- 5" << endl;
    cout << "clearList -------------------------- 6" << endl;
    cout << "QUIT ------------------------------- 0" << endl;

    while(!stop){
        cout << "::> ";
        cin >> choice;
        //some case statments where used again from lab 3 just changed variable names
        switch(choice){
            case(0):
                stop = true;
                break;
            case(1):
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
                if(choice2 == 1){myinput.addItem(input);}else{myinput2.addItem(input);}
                break;
            case(2):
                if(choice2 == 1){testing = myinput.isEmpty();}else{testing = myinput2.isEmpty();}
                if(testing){
                    cout << "List is empty" << endl;
                }else{
                    if(choice2 == 1){temp = myinput.getItem();}else{temp = myinput2.getItem();}
                    cout << "FirstName: " << temp.firstName << endl;
                    cout << "LastName: " << temp.lastName << endl;
                    cout << "M-number: " << temp.m_number << endl; 
                    cout << "Birthday: " << temp.birthday << endl;
                    cout << "GPA: " << temp.gpa << endl << endl;
                }
                break;
            case(3):
                if(choice2 == 1){testing = myinput.isEmpty();}else{testing = myinput2.isEmpty();}
                if(testing){
                    cout << "list is empty" << endl;
                }else{
                    cout << "list is not empty" << endl;
                }
                break;
            case(4):
                if(choice2 == 1){testing = myinput.isFull();}else{testing = myinput2.isFull();}
                if(myinput.isFull()){
                    cout << "list is full" << endl;
                }else{
                    cout << "list is not full" << endl;
                }
                break;
            case(5):
                if(choice2 == 1){testing2 = myinput.size();}else{testing2 = myinput2.size();}
                cout << "size of list: " << testing2 << endl;
                break;
            case(6):
                myinput.clearList();
                myinput2.clearList();
                cout << "list is cleared" << endl;
                break;
        }
    }
}
