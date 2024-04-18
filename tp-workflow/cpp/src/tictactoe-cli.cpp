#include "Tictactoe.hpp"

using namespace std;

int main() {

    Jeu jeu;
    while(!jeu.isFinished()){
        std::cout << jeu;
        jeu.displayStatus();

        std::cout << "Entrez un coup (i,j) : ";
        std::string i;
        std::string j;
        std::cin >> i >> j ;
        jeu.jouer(stoi(i), stoi(j));
        std::cout << std::endl;
    }

    std::cout << jeu;
    jeu.displayStatus();

    return 0;
}

