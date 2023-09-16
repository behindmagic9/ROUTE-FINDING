#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include<climits>
#include<vector>
#include<algorithm>
#include"customhash.h"
#include "Vertex.h"
#include "Edge.h"
#include<limits>

class Graph
{
public:
    Graph() = default;
    std::vector<Vertex> vertices;
    std::unordered_map<std::pair<int, int>, std::string> edgeColors; // Store edge colors using source-destination pair as the key
    std::unordered_map<std::pair<int, int>, int> edgeDistances;      // Store edge distances using source-destination pair as the key

    void insert(const Vertex &newvertex);

    void addEdge(const int &source, const int &destination, const int &distance, const std::string &color = "");
    
    void UpdateEdge(const int &source, const int &destination, const int &distance);

    void UpdateVertex(const int &id, const std::string &name);

    void DeleteEdge(const int &source, const int &destination);
    void DeleteVector(const int &id);

    void print();
    bool checkIfvertexExist(const int &id);
    bool checkIfEdgeExist(const int &source, const int &destination);

    void dijkstrabellman(const std::string &startStation, const std::string &endStation);
    void printPathWithColor(const std::vector<std::string> &pathStations, const std::vector<std::string> &pathColors, const int &shortestDistance);
};

int getIntegerInput(const std::string &prompt);
char getCharInput(const std::string &prompt);

std::string getStringInput(const std::string &prompt);

#endif // GRAPH_H

