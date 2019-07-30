#include "graphs.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
graph::graph()
{
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
}

//Return if the edge exists
bool graph::hasEdge(string i, string j)
{
	node* temp = head;
	while(temp != nullptr){
		if(temp->name.compare(i) == 0){
			if(temp->data.isinList(j) >= 0){
				return true;
			}
		}
		temp = temp->next;
	}
	return false;
}

//May need a lot of work
linked_list graph::inEdges(string i)
{
	linked_list retval;
	node* temp = head;
	while(temp != nullptr){
		if(temp->data.isinList(i) >= 0){
			retval.addItem(temp->name);
		}
		temp = temp->next;
	}
	return retval;
	//return everything connected to j
	//a little harder since we have to find every instance of this in avery node
}

//May need a lot of work
linked_list graph::outEdges(string i)
{
	node* temp = head;
	while(temp != nullptr){
		if(temp->name.compare(i) == 0){
			return temp->data;
		}
		temp = temp->next;
	}
	return linked_list();
	//going to return the linked list everything connected to i
}

//Print the graph


/*I did this approximately with ints instead of nodes, and array instead of linked lists
the logic I believe is there but those are the edits that need to be made. I went ahead and
changed all the ints in the functions to nodes which makes more errors yes but it was easy and shows where we are
may need. Also task 3 needs completely done.*/