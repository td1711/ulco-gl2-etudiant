#include <todolist-cpp/Task.hpp>
#include <catch2/catch.hpp>
#include <todolist-cpp/Board.hpp>

TEST_CASE( "test task struct" ) {
    Task t {1, "TODO"};
    REQUIRE( t._id == 1 );
    REQUIRE( t._name == "TODO" );
}


TEST_CASE( "test Board"){
    Board b;
    b.addTodo("task 1");
}

