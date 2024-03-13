#include "Rectangle.hpp"

Rectangle::Rectangle(double largeur, double hauteur) :
    _largeur(largeur), _hauteur(hauteur)
{}

double Rectangle::aire() const{
    return _largeur * _hauteur;
}

Description Rectangle::toDescription() const{
    Description map;
    map["id"] = "rectangle";
    map["largeur"] = std::to_string(_largeur);
    map["hauteur"] = std::to_string(_hauteur);
};