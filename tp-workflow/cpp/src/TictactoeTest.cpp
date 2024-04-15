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


    std::string s = ". . . \n. . . \n. . . \n";
    std::stringstream display;
    display << jeu;
    REQUIRE(s == display.str());
}

TEST_CASE("Jouer un coup"){
    Jeu jeu;

    REQUIRE(jeu.jouer(2,2));
    REQUIRE(jeu.getStatus() == Status::RougeJoue);
    REQUIRE(jeu.getCell(2, 2) == Cell::Vert);

    REQUIRE(!jeu.jouer(2,2));
    REQUIRE(jeu.getStatus() == Status::RougeJoue); 
    REQUIRE(jeu.getCell(2, 2) == Cell::Vert);

    REQUIRE(!jeu.jouer(3,2));
    REQUIRE(!jeu.jouer(0,3));
    REQUIRE(!jeu.jouer(0,-1));
}

TEST_CASE("Gagner partie"){
    Jeu jeu;

    REQUIRE(jeu.jouer(0,0));
    REQUIRE(jeu.getStatus() == Status::RougeJoue);

    REQUIRE(jeu.jouer(1,1));
    REQUIRE(jeu.getStatus() == Status::VertJoue);

    REQUIRE(jeu.jouer(1,0));
    REQUIRE(jeu.getStatus() == Status::RougeJoue); 

    REQUIRE(jeu.jouer(2,2));
    REQUIRE(jeu.getStatus() == Status::VertJoue); 

    REQUIRE(jeu.jouer(2,0));
    std::cout << jeu;
    REQUIRE(jeu.getStatus() == Status::VertGagne);   
}

    // TODO


