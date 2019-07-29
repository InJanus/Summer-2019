#include <iostream>
#include "..\\Lab_9\graphs\graphs.h"
#include <string>
#include <cstdlib>
#include "graphs.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

	int command;
	bool quit = false;
	int vert1 = 0;
	int vert2 = 0;
	 
	// To use the text file method comment out this main function and follow the 
	// steps on line 91 and 92, also note input methods are on the switch-case.
	int main()
	{
		
		DirectedGraph graph;
		while (quit == false)
		{
				std::cout << "Press 1 to Add an edge." << std::endl;
				std::cout << "Press 2 to Remove an edge." << std::endl;
				std::cout << "Press 3 to Find an edge." << std::endl;								
				std::cout << "Press 4 to Find the out edge." << std::endl;
				std::cout << "Press 5 to Find the in edge" << std::endl;
				std::cout << "Press 6 to Print Array." << std::endl;
				std::cout << "Press 7 to Quit." << std::endl;
				std::cin >> command;

			if (command == 1)
			{
				std::cout << "Enter the two vertices that are on connected to the desired edge." << std::endl;
				std::cout << "Enter vertice one." << std::endl;
				std::cin >> vert1;
				std::cout << "Enter vertice two." << std::endl;
				std::cin >> vert2;

				graph.addEdge(vert1, vert2);

			}
			else if (command == 2)
			{
				std::cout << "Enter the two vertices that are on connected to the desired edge." << std::endl;
				std::cout << "Enter vertice one." << std::endl;
				std::cin >> vert1;
				std::cout << "Enter vertice two." << std::endl;
				std::cin >> vert2;

				graph.removeEdge(vert1, vert2);

			}
			else if (command == 3)
			{
				std::cout << "Enter the two vertices that are on connected to the desired edge." << std::endl;
				std::cout << "Enter vertice one." << std::endl;
				std::cin >> vert1;
				std::cout << "Enter vertice two." << std::endl;
				std::cin >> vert2;

				graph.hasEdge(vert1, vert2);
			}
			else if (command == 4)
			{

				std::cout << "Enter the vertice that is connected to the desired edge." << std::endl;
				std::cin >> vert1;

				std::cout << graph.inEdges(vert1) << std::endl;

			}
			else if (command == 5)
			{
				std::cout << "Enter the vertice that is connected to the desired edge." << std::endl;
				std::cin >> vert1;

				std::cout << graph.outEdges(vert1) << std::endl;
			}
			else if (command == 6)
			{
				std::cout << "Printing Current Graph." << std::endl;
				graph.printGraph();
			}
			else if (command == 7)
			{
				quit = true;
			}
		}
		quit = false;
		
	}