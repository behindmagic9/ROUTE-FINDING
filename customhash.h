#ifndef CUSTOM_HASH_H
#define CUSTOM_HASH_H

#include <functional>
#include <utility>

namespace std
{
    template <>
    struct hash<std::pair<int, int>>
    {
        size_t operator()(const std::pair<int, int> &p) const
        {
            // Custom hash function for std::pair<int, int>
            return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
        }
    };
}

#endif // CUSTOM_HASH_H

