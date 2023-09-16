#include "Edge.h"


const int Edge::get_id() const {
    return E_id;
}

const int &Edge::get_distance() const {
    return Distance;
}

const std::string &Edge::get_color() const {
    return color;
}

const void Edge::set_distance(int distance) {
    Distance = distance;
}

bool Edge::operator==(const int &value) const {
    return E_id == value;
}



