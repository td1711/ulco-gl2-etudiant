#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    // TODO
    return Status::RougeJoue;
}

Cell Jeu::getCell(int i, int j) const {
    return _plateau[j][i];
}

std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
    for (int j = 0; j < 3; ++j){
        for(int i = 0; i < 3; ++i){
            if(jeu.getCell(i, j) == Cell::Vide){
                os << ". "; 
            }
            if(jeu.getCell(i, j) == Cell::Rouge){
                os << "R "; 
            }
            if(jeu.getCell(i, j) == Cell::Vert){
                os << "V "; 
            }
        }
        os << std::endl;
    }
    return os;
}

bool Jeu::jouer(int i, int j) {
    // TODO
    return false;
}

void Jeu::raz() {
    for (int j = 0; j < _plateau.size(); ++j){
        for(int i = 0; i < _plateau.size(); ++i){
            _plateau[j][i] = Cell::Vide;
        }
    }
}

