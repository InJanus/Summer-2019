#include "..\\Lab_7\tree\tree_balanced.h"
#include <iostream>
using namespace std;

int main(){
    tree mytree;

    mytree.insert("a");
    mytree.insert("b");
    mytree.insert("c");
    cout << mytree.height() << endl;
    mytree.print();


    return 0;
}
