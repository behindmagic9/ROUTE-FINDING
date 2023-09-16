#include "Vertex.h"

Vertex::Vertex(int id, std::string name) : V_id{id}, Name{name} {}

const int &Vertex::get_predecessor() const {
    return predecessor;
}

const void Vertex::set_predecessor(const int &path) {
    predecessor = path;
}

const int &Vertex::get_distance() const {
    return distance;
}

const void Vertex::set_distance(const int &num) {
    distance = num;
}

const int &Vertex::get_id() const {
    return V_id;
}

const void Vertex::set_name(const std::string &name) {
    Name = name;
}

const std::string &Vertex::get_name() const {
    return Name;
}

void Vertex::printEdgeList() {    
        std::cout << " [ ";
        for (const auto n : edges)
        {
            std::cout << std::setw(6) << n.get_id() << std::setw(6) << n.get_distance() << std::setw(6) << " --> ";
        }
        std::cout << " ] \n"
                  << std::endl;
    }

bool Vertex::checkIfEdgeexist(const int &id) {
    for (auto &ed : edges) {
        if (ed.get_id() == id) {
            return true;
        }
    }
    return false;
}

const std::string Vertex::getLineColor(int destination) const {
    for (const auto &edge : edges) {
        if (edge.get_id() == destination) {
            return edge.get_color();
        }
    }
    return "Unknown"; // Default color if not found
}

bool Vertex::operator==(const int &value) const {
    return V_id == value;
}

bool Vertex::operator>(const Vertex &rhs) const {
    return get_distance() > rhs.get_distance();
}

bool Vertex::operator<(const Vertex &other) const {
    return get_distance() < other.get_distance();
}

