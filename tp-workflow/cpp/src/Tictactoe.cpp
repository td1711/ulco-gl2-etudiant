#include "Tictactoe.hpp"
#include <vector>

Jeu::Jeu() {
    currentStatus = Status::VertJoue;
    raz();
}

Status Jeu::getStatus() const {
    return currentStatus;
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

bool Jeu::isValidCell(int i, int j){
    return i >= 0 && i < 3 && j >= 0 && j < 3;
}

bool Jeu::hasVictory(int i, int j, int directionI, int directionJ,  Cell color){
    if(!isValidCell(i, j) || _plateau[j][i] != color){
        return 0;
    }

    return 1 + hasVictory(i+directionI, j+directionJ, directionI, directionJ, color);
}

int Jeu::nbFilledCells(){
    int sum = 0;
    for (int j = 0; j < _plateau.size(); ++j){
        for(int i = 0; i < _plateau.size(); ++i){
            if(getCell(i,j) != Cell::Vide){
                sum ++;
            }
        }
    }
    return sum;
}

void Jeu::setStatus(){
    if(nbFilledCells() == 9){
        currentStatus = Status::Egalite;
    }

    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> directions = {
        /*{{0,0}, {1,0}}, // j,i , j,i
        {{0,1}, {1,0}},
        {{0,2}, {1,0}},*/
        {{0,0}, {0,1}},
        /*{{1,0}, {0,1}},
        {{2,0}, {0,1}},
        {{0,0}, {1,1}},
        {{0,2}, {1,-1}},*/
    };
 
    for(auto line : directions){
        auto coord = line.first;
        auto direction = line.second;
        Cell currentColor = getCell(coord.second, coord.first);
        if(currentColor != Cell::Vide && hasVictory(coord.second, coord.first, direction.second, direction.first, currentColor) == 3){          
            std::cout << "///// Gagné ////" << std::endl;
            if(currentColor == Cell::Rouge)
                currentStatus = Status::RougeGagne;
            else
                currentStatus = Status::VertGagne;
            return;
        }
    
    }

    std::cout << std::endl;
        

    if(currentStatus == Status::VertJoue)
        currentStatus = Status::RougeJoue;
    else if(currentStatus == Status::RougeJoue)
        currentStatus = Status::VertJoue;
}

bool Jeu::isFinished(){
    Status status = getStatus();
    return status == Status::Egalite || status == Status::RougeGagne || status == Status::VertGagne;
}

bool Jeu::jouer(int i, int j) {
    if(!isFinished() && getCell(i, j) == Cell::Vide && isValidCell(i, j)){
        if(getStatus() == Status::RougeJoue){
            _plateau[j][i] = Cell::Rouge;
        }
        else{
            _plateau[j][i] = Cell::Vert;  
        }
        setStatus();
        return true;
    }
    return false;
}

void Jeu::raz() {
    for (int j = 0; j < _plateau.size(); ++j){
        for(int i = 0; i < _plateau.size(); ++i){
            _plateau[j][i] = Cell::Vide;
        }
    }
}

