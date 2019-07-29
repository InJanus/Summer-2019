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
	
	int main()
	{
		
		graph graph;
		while (quit == false)
		{
				std::cout << "Press 1 to Add an edge." << std::endl;
				std::cout << "Press 2 to Remove an edge." << std::endl;
				std::cout << "Press 3 to Find an edge." << std::endl;								
				std::cout << "Press 4 to Find the out edge." << std::endl;
				std::cout << "Press 5 to Find the in edge" << std::endl;
                std::cout << "Press 6 to Quit." << std::endl;
				std::cout << "Press 7 to Print Array." << std::endl;
				std::cin >> command;

			switch(command)
			{
            case (1):
				std::cout << "Enter the two vertices that are on connected to the desired edge." << std::endl;
				std::cout << "Enter vertice one." << std::endl;
				std::cin >> vert1;
				std::cout << "Enter vertice two." << std::endl;
				std::cin >> vert2;

				graph.addEdge(vert1, vert2);
                break;

			case (2):
				std::cout << "Enter the two vertices that are on connected to the desired edge." << std::endl;
				std::cout << "Enter vertice one." << std::endl;
				std::cin >> vert1;
				std::cout << "Enter vertice two." << std::endl;
				std::cin >> vert2;

				graph.removeEdge(vert1, vert2);
                break;
			case (3):
				std::cout << "Enter the two vertices that are on connected to the desired edge." << std::endl;
				std::cout << "Enter vertice one." << std::endl;
				std::cin >> vert1;
				std::cout << "Enter vertice two." << std::endl;
				std::cin >> vert2;

				graph.hasEdge(vert1, vert2);
                break;
			case (4)

				std::cout << "Enter the vertice that is connected to the desired edge." << std::endl;
				std::cin >> vert1;

				std::cout << graph.inEdges(vert1) << std::endl;
                break;
			case (5):
				std::cout << "Enter the vertice that is connected to the desired edge." << std::endl;
				std::cin >> vert1;

				std::cout << graph.outEdges(vert1) << std::endl;
                break;
			case (6):
				quit = true;
                break;
			case (7):
                std::cout << "Printing Current Graph." << std::endl;
				graph.printGraph();
                break;
            default:
                std::cout << "Invalid Input"<< std::endl; 
		}
		quit = false;
		
	}