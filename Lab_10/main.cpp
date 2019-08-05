#include <iostream>
#include "..\\Lab_10\hash\hash.h"
#include <cstdio>
#include <cstdlib>
using namespace std;


int main() {
	string inElement;
	int option;
	int task;
    bool flag=true;
	//while (flag) {
    cout<<"1) Task 1-2 \n2) Task 3\nEnter Menu Value: "<<endl;
    cin >>task;
    if (task == 1){
        HashTable hash;
        cout << "1) Insert Element" << endl;
        cout << "2) Search Element" << endl;
        cout << "3) Delete Element" << endl;
        cout << "4) Print Table"<< endl;
        cout << "5) Number of Elements"<< endl;
        cout << "6) Exit" << endl;
        while(flag){
            cout << "Enter Option: ";
            cin >> option;
            if(option == 1){
                cout << "Enter element to be inserted: ";
                cin >> inElement;
                hash.addItem(inElement);
                hash.print();
            }
            else if(option == 2){
                cout << "Enter value of the element to be searched: ";
                cin >> inElement;
                cout<<"Search Result: "<<endl;
                hash.getItem(inElement);
            }
            else if(option == 3){
                cout << "Enter value of the element to be deleted: ";
                cin >> inElement;
                hash.RemoveItem(inElement);
            }
            else if(option == 4){
                hash.print();
            }
            else if(option == 5){
                cout<<"Size of the Hash Table: "<<hash.getLength() << endl;
            }
            else if(option == 6){
                flag =false;
            }
            else{
                cout << "\n Enter correct option \n";
                //[FIXME] Enters Infinite loop if I put in a wrong option. easy fix idk rn
            }
        }
    }else if (task == 2){
        for( int j =0; j<4; j++){
            for( int i=0; i<3;i++){
                int hashsize;
                if (i == 0){
                    hashsize = 100;
                }
                else if( i == 1){
                    hashsize = 200;
                }
                else if(i == 2){
                    hashsize = 500;
                }
                HashTable hash(hashsize);
                for (int i=0;i< hashsize;i++){
                    hash.addItem(hash.randStringCreate(),j);
                }
                hash.print();
                cout<< "HashTable Size: "<<hashsize<<endl<<"Number of Letters used in HashFunction: "<<j;
                cout<< "Number of Collisions: "<<hash.getCollisions()<<endl;
            }
        }
	//cout<< "rand value: "<<hash.randStringCreate()<<endl;   //Testing
    }
    return 0;
}