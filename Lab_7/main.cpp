#include "..\\Lab_7\tree\tree_balanced.h"
#include <iostream>
using namespace std;

int main(){
    tree mytree;
    mytree.insert("b");
    mytree.insert("a");
    mytree.insert("d");
    mytree.insert("c");
    mytree.insert("e");
    //mytree.print();
    mytree.insert("f");
    cout<<endl;
    mytree.print();
    return 0;
}
