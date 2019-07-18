#include "tree_balanced.h"
#include <iostream>
using namespace std;

string retval[100];

void printNode(Node* temp, int level){
    if(temp->right == nullptr && temp->left == nullptr){
        cout << "level: " << level << " -- " << temp->data << endl;
    }else if(temp->right == nullptr && temp->left != nullptr){
        printNode(temp->left, level+1);
        cout << "level: " << level << " -- " << temp->data << endl;
    }else if(temp->right != nullptr && temp->left == nullptr){
        printNode(temp->right, level+1);
        cout << "level: " << level << " -- " << temp->data << endl;
    }else{
        printNode(temp->right, level+1);
        printNode(temp->left, level+1);
        cout << "level: " << level << " -- " << temp->data << endl;
    }
}

void tree::printTree(){
    printNode(Head, 0);
}

tree::tree(){
    count2 = 0;
    Head = nullptr;
}

tree::~tree(){
    //empty();
}

void tree::Insert(string input){
	Node* n = new Node();
	Node* parent;
	n->data = input;
	n->left = NULL;
	n->right = NULL;
	parent = NULL;
	if (Size() == 0)
	{
		Head = n;
	}
	else
	{
		Node* current;
		current = Head;
		while (current)
		{
			parent = current;
			if (n->data > current->data)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
		if (n->data < parent->data){
			parent->left = n;
        }else{
			parent->right = n;
        }
	}
	count2++;
}

int tree::Size()
{
	return count2;
}

void tree::Order()
{
	preOrder(Head);
}

void tree::preOrder(Node* node)
{
	if (node == NULL)
		return;
	//cout << node->data << " ";
	l_node.push_back(node->data);

	preOrder(node->left);
	preOrder(node->right);
}

void tree::remakeTree()
{
	delete Head;
    Head = nullptr;
    count2 = 0;
	l_node.sort();
	int s = l_node.size();
	int mid = s / 2;
	vector<string> v_node{ l_node.begin(), l_node.end() };
	Insert(v_node.at(mid));

	Test(v_node, 1, mid - 1);
	Test(v_node, mid + 1, s - 1);

    Insert(v_node.at(0));
}

void tree::Test(vector<string> v_node, int start, int end)
{
	if (start > end)
		return;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;

	Insert(v_node.at(mid));

	Test(v_node, start, mid - 1);
	Test(v_node, mid + 1, end);
}

void tree::Remove(string input)
{
	bool found = false;
	if (Size() == 0)
	{
		cout << "Empty! " << endl;
		return;
	}
	Node* current;
	Node* parent;
	current = Head;
	while (current != NULL)
	{
		if (current->data == input)
		{
			found = true;
			break;
		}
		else
		{
			parent = current;
			if (input > current->data)
			{
				current = current->right;
			}
			else
			{
				current = current->left;
			}
		}
	}
	parent = current;
	if (!found)
	{
		cout << "String not found! " << endl;
		return;
	}
	count2--;
    
	//Single Node
	if ((current->left == NULL && current->right != NULL) || (current->left != NULL
		&& current->right == NULL))
	{
		if (current->left == NULL && current->right != NULL)
		{
			if (parent->left == current)
			{
				parent->left = current->right;
				delete current;
			}
			else
			{
				parent->right = current->right;
				delete current;
			}
		}
		else
		{
			if (parent->left == current)
			{
				parent->left = current->left;
				delete current;
			}
			else
			{
				parent->right = current->left;
				delete current;
			}
		}
		return;
	}
	//Leaf Node
	if (current->left == NULL && current->right == NULL)
	{
		if (parent->left == current) parent->left = NULL;
		else parent->right = NULL;
		delete current;
		return;
	}
	// 2 Children
	if (current->left != NULL && current->right != NULL)
	{
		Node* check;
		check = current->right;
		if ((check->left == NULL) && (check->right == NULL))
		{
			current = check;
			delete check;
			current->right = NULL;
		}
		else
		{
			if ((current->right)->left != NULL)
			{
				Node* left_current;
				Node* lcurrp;
				lcurrp = current->right;
				left_current = (current->right)->left;
				while (left_current->left != NULL)
				{
					lcurrp = left_current;
					left_current = left_current->left;
				}
				current->data = left_current->data;
				delete left_current;
				lcurrp->left = NULL;
			}
			else
			{
				Node* tmp;
				tmp = current->right;
				current->data = tmp->data;
				current->right = tmp->right;
				delete tmp;
			}
		}
		return;
	}
}
