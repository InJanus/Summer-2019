#include <iostream>
#include "..\\Lab_9\graphs\graphs.h"
#include <string>

int command;
bool quit = false;
string vert1;
linked_list vert2;
string input;

using namespace std;

int main()
{
	cout << "Press 1 to Add an edge." << endl;
	cout << "Press 2 to Remove an edge." << endl;
	cout << "Press 3 to Find an edge." << endl;								
	cout << "Press 4 to Find the out edge." << endl;
	cout << "Press 5 to Find the in edge" << endl;
	cout << "Press 6 to Quit." << endl;
	cout << "Press 7 to Print Array." << endl;
	graph graph;
	while (quit == false)
	{

		cout << "Command: ";
		fflush(stdin);
		cin >> command;

		switch(command)
		{
		case (1):
			cout << "Enter the two vertices that are on connected to the desired edge." << endl;
			cout << "Enter vertice one." << endl;
			fflush(stdin);
            getline(cin, vert1);
			cout << "Enter vertice two. (enter 0 to stop)" << endl;
			// cin >> vert2;
			vert2.removeAll();
			input = "";
			while(input.compare("0") != 0){
				fflush(stdin);
				getline(cin, input);
				if(input.compare("0") != 0){
					vert2.addItem(input);
				}
			}

			graph.addEdge(vert1, vert2);
			break;

		case (2):
			cout << "Enter the two vertices that are on connected to the desired edge." << endl;
			cout << "Enter vertice one." << endl;
			fflush(stdin);
            getline(cin, vert1);
			cout << "Enter vertice two. (enter 0 to stop)" << endl;
			// cin >> vert2;
			vert2.removeAll();
			input = "";
			while(input.compare("0") != 0){
				fflush(stdin);
				getline(cin, input);
				if(input.compare("0") != 0){
					vert2.addItem(input);
				}
			}
			graph.removeEdge(vert1, vert2);
			break;
		case (3):
			cout << "Enter the two vertices that are on connected to the desired edge." << endl;
			cout << "Enter vertice one." << endl;
			fflush(stdin);
            getline(cin, vert1);
			cout << "Enter vertice two." << endl;
			
			fflush(stdin);
            getline(cin, input);

			if(graph.hasEdge(vert1, input)){
				cout << "edge exists" << endl;
			}else{
				cout << "edge does not exist" << endl;
			}
			break;
		case (4):

			cout << "Enter the vertice that is connected to the desired edge." << endl;
			cin >> vert1;

			//cout << graph.inEdges(vert1) << endl;
			break;
		case (5):
			cout << "Enter the vertice that is connected to the desired edge." << endl;
			cin >> vert1;

			//cout << graph.outEdges(vert1) << endl;
			break;
		case (6):
			quit = true;
			break;
		case (7):
			cout << "Printing Current Graph." << endl;
			graph.printGraph();
			break;
		default:
			cout << "Invalid Input"<< endl; 
	}
	quit = false;
	
	}
}