#include <iostream>
#include "..\\Lab_10\hash\hash.h"
#include <cstdio>
#include <cstdlib>
using namespace std;


int main() {
	HashTable hash;
	string inElement;
	int option;
    bool flag=true;
	while (flag) {
		cout << "1) Insert Element" << endl;
		cout << "2) Search Element" << endl;
		cout << "3) Delete Element" << endl;
        cout << "4) Print Table"<< endl;
		cout << "5) Number of Elements"<< endl;
		cout << "6) Exit" << endl;
		cout << "Enter Option: ";
		cin >> option;
		if(option==1){
			cout << "Enter element to be inserted: ";
			cin >> inElement;
			hash.addItem(inElement);
            hash.print();
        }
		else if(option==2){
			cout << "Enter value of the element to be searched: ";
			cin >> inElement;
            cout<<"Search Result: "<<endl;
            hash.getItem(inElement);
        }
		else if(option ==3){
			cout << "Enter value of the element to be deleted: ";
			cin >> inElement;
			hash.RemoveItem(inElement);
        }
		else if(option == 4){
			hash.print();
        }
		else if(option == 5){
            cout<<"Size of the Hash Table: "<<hash.getLength();
        }
        else if(option == 6){
            flag =false;
        }
		else{
			cout << "\n Enter correct option \n";
			//[FIXME] Enters Infinite loop if I put in a wrong option. easy fix idk rn
		}
	}
	return 0;
}
