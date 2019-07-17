#include "..\\Lab_7\tree\tree_balanced.h"
#include <iostream>
using namespace std;

int main(){
    tree mytree;
    mytree.insert("b");
    mytree.insert("a");
    mytree.insert("c");
    mytree.insert("d");
    //mytree.print();
    mytree.insert("e");
    cout<<endl;
    mytree.print();
    return 0;
    /* 
    tree BTree;

	bool endInput = false;
	while (!endInput)
	{
		int choice = 0;
		cout << "Type 1: to insert number, 2: to remove number, 3: to exit app." << endl;
		cin >> choice;
		int input = 0;
		switch (choice)
		{
			case 1: //Insert
				cout << "Enter integer you wish to add: ";
				cin >> input;
				BTree.Insert(input);
				break;
			case 2: //Remove
				cout << "Enter integer you wish to remove: ";
				cin >> input;
				BTree.Remove(input);
				break;
			case 3: //End
				cout << "App Closing..." << endl;
				endInput = true;
				BTree.Order();
				BTree.remakeTree();
				break;
			default: //Incorrect
				cout << "Incorrect option." << endl;
				break;
		}
	}
		system("pause");
	return 0;
}
*/
}
