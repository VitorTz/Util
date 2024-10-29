#pragma once
#include <cstddef>


std::size_t hash(const char* s);


std::size_t hash(const char* s) {
    std::size_t hash = 5381;
    int c;
    while ((c = *s++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}