#include <iostream>
#include "..\\Lab_6\tree\tree.h"

using namespace std;

int main(){
    tree mytree;
    int size = 4;

    string add1[] = {"Star Wars", "Star Trek", "Space Balls", "Galaxy Quest"};
    string add2[] = {"Cars", "Monsters, Inc", "The Incredibles", "Wall-E"};
    string add3[] = {"Halloween", "A Nightmare On Elm Street", "Hocus Pocus", "Beetlejuice"};

    for(int i = 0; i < size; i++){
        mytree.insert(add1[i]);
        mytree.insert(add2[i]);
        mytree.insert(add3[i]);
    }
    cout << "Accending" << endl << endl;
    string* temp = mytree.getAllAcending();
    for(int i = 0; i < size*3; i++){
        cout << i << " - " << temp[i] << endl;
    }
    cout << "Decending" << endl << endl;
    temp = mytree.getAllDecending();
    for(int i = 0; i < size*3; i++){
        cout << i << " - " << temp[i] << endl;
    }


}