#include "graphs.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
graph::graph()
{
	// Auto populate the linkedList of vertices to be between 0 and 9;
	// for (int i = 0; i < linkedList.size(); i++)
	// {
	// 	linkedList[i].push_back(i);
	// }
	size = 0;
	head = nullptr;
}

//Destructor
graph::~graph()
{
}

//Add an edge but if invalid then tell them.
void graph::addEdge(string i, linked_list j)
{
	if(head == nullptr){
		head = new node();
		for(int a = 0; a < j.size(); a++){
			head->data.addItem(j.seeNext().name);
		}
		head->name = i;
		head->next = nullptr;
	}else{
		node* temp = head;
		while(temp->next != nullptr){
			temp = temp->next;
		}
		temp->next = new node();
		temp = temp->next;
		temp->name = i;
		for(int a = 0; a < j.size(); a++){
			temp->data.addItem(j.seeNext().name);
		}
	}
	size++;
}

void graph::printGraph()
{
	node* temp = head;
	for(int i = 0; i < size; i++){
		cout << "Name: " << temp->name << endl;
		for(int j = 0; j < temp->data.size(); j++){
			cout << "node " << j << " -- = " << temp->data.seeAt(j).name << endl;
		}
		temp = temp->next;
	}

	// for (int i = 0; i < 10; i++)
	// {
	// 	cout << "[" << i << "]";
	// 	if (!linkedList[i].empty())
	// 	{
	// 		for (int j = 0; j < linkedList[i].size(); j++)
	// 		{
	// 			cout << "->(" << linkedList[i].at(j) << ")";
	// 		}
	// 	}
	// 	cout << endl;
	// }
}

//Remove edge but if does not exist inform them.
void graph::removeEdge(string i, linked_list j)
{
	node* prev = head;
	node* temp = head;
	while(temp != nullptr){
		if(temp->name.compare(i) == 0){
			if(temp->data.equalto(j)){
				if(prev == temp){
					//head case
					head = head->next;
				}else{
					prev->next = prev->next->next;
					
				}
				break;
			}
		}
		prev = temp;
		temp = temp->next;
	}
	size--;
    // See if this edge exists.
	// if (this->hasEdge(i, j)) 
	// {
	// 	for (int k = 0; k < linkedList[i].size(); k++)
	// 	{
	// 		if (linkedList[i].at(k) == j)
	// 		{
	// 			linkedList[i].erase(linkedList[i].begin() + k);
	// 		}
	// 	}
	// }else{
	//     std::cout << "Edge does not exist" << std::endl;
    // }
}

//Return if the edge exists
bool graph::hasEdge(node i, node j)
{
	//check to see if an edge exists in the one you are looking for


	// if (!linkedList[i].empty())
	// {
	// 	for (int k = 0; k < linkedList[i].size(); k++)
	// 	{
	// 		if (linkedList[i].at(k) == j)
	// 		{
	// 			return true;
	// 		}
	// 	}
	// }
	// return false;
}

//May need a lot of work
string graph::outEdges(node i)
{
	// string retString = "";
	// if (linkedList[i].empty())
	// {
	// 	return (to_string(i) + " has no out edges.");
	// }
	// else
	// {
	// 	retString += to_string(i) + " outEdges: ";
	// 	for (int j = 0; j < linkedList[i].size(); j++)
	// 	{
	// 		retString += to_string(linkedList[i].at(j)) + " ";
	// 	}

	// 	return retString;
	// }
}

//May need a lot of work
string graph::inEdges(node i)
{
	// string retString = to_string(i) + " inEdges: ";
	// for (int j = 0; j < 10; j++)
	// {
	// 	if (!linkedList[j].empty())
	// 	{
	// 		for (int k = 0; k < linkedList[j].size(); k++)
	// 		{
	// 			if (linkedList[j].at(k) == i)
	// 			{
	// 				retString += to_string(j) + " ";
	// 			}
	// 		}
	// 	}
	// }

	// if (retString == (to_string(i)  + " inEdges: "))
	// {
	// 	return (to_string(i) + " has no edges.");
	// }
	// else
	// {
	// 	return retString;
	// }
}

//Print the graph


/*I did this approximately with ints instead of nodes, and array instead of linked lists
the logic I believe is there but those are the edits that need to be made. I went ahead and
changed all the ints in the functions to nodes which makes more errors yes but it was easy and shows where we are
may need. Also task 3 needs completely done.*/