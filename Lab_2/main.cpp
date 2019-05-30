#include <iostream>
#include <stdio.h>
#include <string.h>
#include "..\Lab_2\queue\queue.h"
#include "..\Lab_2\stack\stack.h"
using namespace std;

//main function of the Lab
int main(){
    string mystring;
    int select;
    bool stop = false;
    
        cout << "Please enter phrase: ";
        getline(cin, mystring);
        int n = mystring.length();
        char *char_array = new char[n + 1];
        strcpy(char_array, mystring.c_str()); 

    //conditional to test when to end the program
    while(!stop){
        cout << "Little endian (1), Big endian (2), enter new phrase(3), test stack(4), test queue(5), or exit(0): ";
        cin >> select;
        //Return the array backwards (big endian)
        if (select == 2){
            stack mystack;
            queue myqueue;
            for(int i = 0; i < mystring.length(); i++){
                mystack.push((int)char_array[i]);
            }
            for(int i = 0; i < mystring.length(); i++){
                myqueue.enqueue(mystack.pop());
            }
            myqueue.printString();
            cout << endl;
        //return the array as entered (little endian)
        }else if(select == 1){
            queue myqueue;
            queue myqueue2;
            for(int i = 0; i < mystring.length(); i++){
                myqueue.enqueue((int)char_array[i]);
            }
            for(int i = 0; i < mystring.length(); i++){
                myqueue2.enqueue(myqueue.dequeue());
            }
            myqueue2.printString();
            cout << endl;
        //Enter a new phrase 
        }else if(select == 3){
            cout << "Please enter phrase: ";
            cin.clear();
            fflush(stdin);
            getline(cin, mystring);
            n = mystring.length();
            char_array = new char[n + 1];
            strcpy(char_array, mystring.c_str());
        }else if(select == 0){
            stop = true;
        }else if(select == 4){
            bool stop4 = false;
            int input;
            cout << "Enter 0 to stop" << endl << "1 to Pop" << endl << "2 to show Topper" << endl << "3 for Length" << endl;
            cout << "Any other number to push" << endl;
            stack newstack;
            while(!stop4){
                cin >> input;
                if(input == 0){
                    stop4 = true;
                }else if(input == 1){
                    cout << "pop: " << newstack.pop() << endl;
                }else if(input == 2){
                    cout << "topper: " << newstack.topper() << endl;
                }else if(input == 3){
                    cout << "length: " << newstack.length() << endl;
                }else{
                    newstack.push(input);
                }
            }
        }else if(select == 5){
            bool stop5 = false;
            int input;
            cout << "Enter 0 to stop" << endl << "1 to dequeue" << endl << "2 to show isFull" << endl << "3 to show isEmpty" << endl;
            cout << "Any other number to push" << endl;
            queue newqueue;
            while(!stop5){
                cin >> input;
                if(input == 0){
                    stop5 = true;
                }else if(input == 1){
                    cout << "dequeue: " << newqueue.dequeue() << endl;
                }else if(input == 2){
                    cout << "isFull: " << newqueue.isFull() << endl;
                }else if(input == 3){
                    cout << "isEmpty: " << newqueue.isEmpty() << endl;
                }else{
                    newqueue.enqueue(input);
                }
            }
        }else{
            cout << "Invalid Option (enter new value)" << endl; 
        }
    }

    
    return 0;
}
