#include "Disque.hpp"
#include <cmath>

Disque::Disque(double rayon) :
    _rayon(rayon)
{}

double Disque::aire() const{
    return _rayon * 2 * M_PI;
}

Description Disque::toDescription() const{
    Description map;
    map["id"] = "disque";
    map["rayon"] = std::to_string(_rayon);
};
