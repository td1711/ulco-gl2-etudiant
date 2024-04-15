#include "Tictactoe.hpp"
#include <sstream>

#include <catch2/catch.hpp>

TEST_CASE("Test Moteur jeu") {
    Jeu jeu;
    
    for(int j=0; j<3; j++){
        for(int i=0; i<3; i++){
            REQUIRE( jeu.getCell(0,0) == Cell::Vide );
        }
    }
}


    // TODO


