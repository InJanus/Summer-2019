#include <iostream>
#include "..\\Lab_6\tree\tree.h"

using namespace std;

int main(){
    tree mytree;
    mytree.insert("d");
    mytree.insert("c");
    mytree.insert("e");
    mytree.insert("a");
    mytree.insert("b");
    mytree.print();
    cout << mytree.getSize() << endl;
    string* temp;
    temp = mytree.getAllAcending();
    for(int i = 0; i < mytree.getSize(); i++){
        cout << temp[i] << endl;
    }
    mytree.remove("b");
    temp = mytree.getAllAcending();
    for(int i = 0; i < mytree.getSize(); i++){
        cout << temp[i] << endl;
    }
    // cout << mytree.find("b")->data << endl;
    //mytree.empty();
    // cout << mytree.getSize() << endl;
}