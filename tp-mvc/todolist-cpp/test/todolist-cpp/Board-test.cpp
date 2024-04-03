#include <todolist-cpp/Board.hpp>
#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "Test Add Task to Board"){
    Board b;
    Task t = b.addTodo("Task 1");
    REQUIRE(t._id == 0);
}
