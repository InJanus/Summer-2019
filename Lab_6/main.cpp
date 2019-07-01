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
    cout << mytree.find("b")->data << endl;
    cout << mytree.getSize() << endl;
}