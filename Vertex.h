#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include<iomanip>
#include <list>
#include <vector>
#include <string>
#include"customhash.h"
#include "Edge.h"

class Vertex {
private:
    int V_id{};
    std::string Name{};
    int distance{};
    int predecessor{};

public:
    Vertex() = default;
    Vertex(int id, std::string name);
    std::list<Edge> edges;
    std::vector<std::string> linecolor;

    const int& get_predecessor() const;
    const void set_predecessor(const int& path);
    const int& get_distance() const;
    const void set_distance(const int& num);
    const int& get_id() const;
    const void set_name(const std::string& name);
    const std::string& get_name() const;
    void printEdgeList();
    bool checkIfEdgeexist(const int& id);
    const std::string getLineColor(int destination) const;
    bool operator==(const int& value) const;
    bool operator>(const Vertex& rhs) const;
    bool operator<(const Vertex& other) const;
};

#endif // VERTEX_H


