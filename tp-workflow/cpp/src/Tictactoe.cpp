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

Cell Jeu::hasVictory(){
    bool winDiagoLeft = true;
    bool winDiagoRight = true;
    Cell colorDiagoLeft = _plateau[0][0];
    Cell colorDiagoRight = _plateau[0][2];

    for(int k=0; k<3; k++){
        Cell colorLine = _plateau[k][0];
        Cell colorColumn = _plateau[0][k];
        bool winLine = true;
        bool winColumn = true;

        if(colorLine == Cell::Vide){
            winLine = false;
        }
        if(colorColumn == Cell::Vide){
            winColumn = false;
        }
        if(colorDiagoLeft == Cell::Vide || _plateau[k][k] != colorDiagoLeft){
            winDiagoLeft = false;
        }
        if(colorDiagoRight == Cell::Vide || _plateau[k][2-k] != colorDiagoRight){
            winDiagoRight = false;
        }


        for(int i=0; i<3; i++){
            if(_plateau[k][i] != colorLine){
                winLine = false;
            }
            if(_plateau[i][k] != colorColumn){
                winColumn = false;
            }
        }
        if(winLine){
            return colorLine;
        }
        if(winColumn){
            return colorColumn;
        }
    }
    if(winDiagoLeft){
        return colorDiagoLeft;
    }
    if(winDiagoRight){
        return colorDiagoRight;
    }
    return Cell::Vide;
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

    Cell winner = hasVictory();
    if(winner != Cell::Vide){
        if(winner == Cell::Rouge){
            currentStatus = Status::RougeGagne;
        }
        else{
            currentStatus = Status::VertGagne;
        }
    
    }



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


void Jeu::displayStatus(){
    if(currentStatus == Status::RougeGagne){
        std::cout << "rouge gagne" << std::endl;
    }
    if(currentStatus == Status::VertGagne){
        std::cout << "vert gagne" << std::endl;
    }
    if(currentStatus == Status::RougeJoue){
        std::cout << "rouge joue" << std::endl;
    }
    if(currentStatus == Status::VertJoue){
        std::cout << "vert joue" << std::endl;
    }
    if(currentStatus == Status::Egalite){
        std::cout << "égalité" << std::endl;
    }
}