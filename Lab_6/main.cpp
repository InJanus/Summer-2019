#include <iostream>
#include "..\\Lab_6\tree\tree.h"

using namespace std;

int main(){
    tree mytree;
    mytree.insert("e");
    mytree.insert("d");
    mytree.insert("b");
    mytree.insert("a");
    mytree.insert("c");
    //mytree.insert("f");
    //mytree.insert("b");
    mytree.print();
    // cout << mytree.getSize() << endl;
    // string* temp;
    mytree.remove("e");
    mytree.print();
    // temp = mytree.getAllAcending();
    // for(int i = 0; i < mytree.getSize(); i++){
    //     cout << temp[i] << endl;
    // }
    //mytree.remove("c");
    // cout << mytree.find("b")->data << endl;
    //mytree.empty();
    // cout << mytree.getSize() << endl;
}