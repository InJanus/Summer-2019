#include "..\\Lab_7\tree\tree_balanced.h"
#include <iostream>
using namespace std;

int main(){
    /* 
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
    */
    tree BTree;

	bool endInput = false;
	while (!endInput)
	{
		int choice = 0;
		cout << "Type 1: to insert string, 2: to remove string, 3: to exit app." << endl;
		cin >> choice;
		string input;
		switch (choice)
		{
			case 1: //Insert a node
				cout << "Enter string to add: ";
                fflush(stdin);
				getline(cin, input);
				BTree.Insert(input);
				break;
			case 2: //Remove a node
				cout << "Enter string to remove: ";
			    fflush(stdin);
				getline(cin, input);
				BTree.Remove(input);
				break;
			case 3: //End
				cout << "Ending Program" << endl;
				endInput = true;
				BTree.Order();
				BTree.remakeTree();
				break;
			default: //Incorrect
				cout << "Invalid Option" << endl;
				break;
		}
        BTree.printTree();
	}
	cin.get();
	return 0;
}
