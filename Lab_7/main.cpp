#include "..\\Lab_7\tree\tree_balanced.h"
#include <iostream>
using namespace std;

int main(){
    tree mytree;

    mytree.insert("b");
    mytree.insert("a");
    mytree.insert("c");
    mytree.insert("d");
    mytree.insert("d");
    cout << mytree.height() << endl;
    mytree.print();
    node* temp1 = mytree.find("c");

    node* temp2 = mytree.find("b");
    mytree.rotateleft(temp1, temp2);
    mytree.print();


    return 0;
}
