// to compile - > g++ -o a.out main.cpp Graph.cpp Edge.cpp execute.cpp Vertex.cpp 

#include <iostream>
#include <iomanip>
#include <vector>
#include"execute.h"
#include"Graph.h"

int main()
{
    Graph g;
    
    executeGraphOperations(g);
    std::string s;
    char choice;

    while (choice != 'Q' && choice != 'q')
    {
        std::cout << "Enter A to add  vertex: " << std::endl;
        std::cout << "Enter E for adding edge " << std::endl;
        std::cout << "Enter U for Updating distance in edge " << std::endl;
        std::cout << "Enter S for Geting shorttest path from a source" << std::endl;
        std::cout << "Enter V for Updating Vertex " << std::endl;
        std::cout << "Enter D for deleting the edge " << std::endl;
        std::cout << "Enter X for deleting the Vertex " << std::endl;
        std::cout << "Enter P for printing " << std::endl;
        std::cout << "Enter Q to quit : " << std::endl;
        char choice = getCharInput("Please enter your choice : ");
        if (::toupper(choice) >= 'A' && ::toupper(choice) <= 'Z')
        {
            switch (::toupper(choice))
            {

            case 'A':
            {
                int id = getIntegerInput("Enter the id : ");
                std::string name = getStringInput("Enter the name of the Station : ");
                Vertex v(id, name);
                g.insert(v);
                break;
            }

            case 'E':
            {
                int source = getIntegerInput("Enter the source id : ");
                int destination = getIntegerInput("Enter the destination id :");
                int distance = getIntegerInput("Enter the weight of edge : ");
                std::string color = getStringInput("Enter teh color of the edge : ");
                g.addEdge(source, destination, distance, color);
                break;
            }
            case 'U':
            {
                int source = getIntegerInput("Enter the source id : ");
                int destination = getIntegerInput("Enter the destination id :");
                int distance = getIntegerInput("Enter the Updated weight of edge : ");
                g.UpdateEdge(source, destination, distance);
                break;
            }
            case 'V':
            {
                int Vector_id = getIntegerInput("Enter the source id : ");
                std::string name = getStringInput("Enter the Updated name : ");
                g.UpdateVertex(Vector_id, name);
                break;
            }
            case 'S':
            {
                std::string startName = getStringInput("Please enter the source station name: ");
                std::string destinationName = getStringInput("Please enter the destination station name: ");
                g.dijkstrabellman(startName, destinationName);
                break;
            }
            case 'D':
            {
                int source = getIntegerInput("Enter the source id : ");
                int destination = getIntegerInput("Enter the destination id :");
                g.DeleteEdge(source, destination);
                break;
            }
            case 'X':
            {
                int Vector_id = getIntegerInput("Enter the source id : ");
                g.DeleteVector(Vector_id);
                break;
            }
            case 'P':
            {
                std::cout << "Printing : ... \n"
                          << std::endl;
                g.print();
                break;
            }
            case 'Q':
            {
                std::cout << "THANKS FOR USING THIS PROGRAM\n";
                break;
            }
            default:
            {
                std::cout << "\nrenter the value\n"
                          << std::endl;
                break;
            }
            }
        }
        else
        {
            std::cout << "\nInvalid choice. Please enter a valid option.\n"
                      << std::endl;
        }
    }
    return 0;
}
