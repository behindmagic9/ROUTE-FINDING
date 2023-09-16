#ifndef EDGE_H
#define EDGE_H

#include <string>
#include"customhash.h"

class Edge
{
    int E_id{};
    int Distance{};
    std::string color;

public:
    Edge() = default;
    Edge(int id, int distance, const std::string &edgeColor = "") : E_id{id}, Distance{distance}, color(edgeColor) {}

    const int get_id() const;

    const int &get_distance() const;
    const std::string &get_color() const;
    const void set_distance(int distance);
    bool operator==(const int &value) const;
};

#endif // EDGE_H

