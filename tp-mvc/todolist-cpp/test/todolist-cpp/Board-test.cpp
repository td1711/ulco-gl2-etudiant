#include <todolist-cpp/Board.hpp>
#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "Test Add Task in Board"){
    Board b;
    b.addTodo("Task 1");
    REQUIRE(b._todo.size() == 1);
    REQUIRE(b._done.size() == 0);

    auto t = b._todo.back();
    REQUIRE( t._id == 1);
    REQUIRE( t._name == "Task 1");
}

TEST_CASE( "Test Add 2 Tasks in Board"){
    Board b;
    b.addTodo("Task 1");
    b.addTodo("Task 2");

    REQUIRE(b._todo.size() == 2);
    REQUIRE(b._done.size() == 0);

    auto t = b._todo.back();
    REQUIRE( t._id == 2);
    REQUIRE( t._name == "Task 2");
}


TEST_CASE( "Test ToDone in Board"){
    Board b;
    b.addTodo("Task 1");
    b.toDone(1);
    REQUIRE(b._todo.size() == 0);
    REQUIRE(b._done.size() == 1);

    auto t = b._done.back();
    REQUIRE( t._id == 1);
    REQUIRE( t._name == "Task 1");
}