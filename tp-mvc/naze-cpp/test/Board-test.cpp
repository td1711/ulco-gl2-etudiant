
#include <Board.hpp>

#include <catch2/catch.hpp>

class BoardTest : public Board {
    public:
        BoardTest(int i, int j) : Board(i, j) {}
};

TEST_CASE( "init, 1" ) {
    Board b;
    REQUIRE( b.getI() == 0 );
    REQUIRE( b.getJ() == 0 );
}

TEST_CASE( "init, 2" ) {
    BoardTest b(1,2);
    REQUIRE( b.getI() == 1 );
    REQUIRE( b.getJ() == 2 );
}

TEST_CASE( "tryGoLeft, ok" ) {
    BoardTest b(7,1);
    b.tryGoLeft();
    REQUIRE( b.getI() == 7 );
    REQUIRE( b.getJ() == 0 );

    b.tryGoLeft();
    REQUIRE( b.getJ() == 0 );

}

// TODO

