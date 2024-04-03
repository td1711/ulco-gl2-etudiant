#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <catch2/catch.hpp>

TEST_CASE( "show Task" ){
    Task t {1, "TASK"};
    std::string res = showTask(t);
    REQUIRE( res == "[1] TASK");
}

TEST_CASE( "show Board" ){
    Board b;
    b.addTodo("Task 1");
    b.addTodo("Task 2");
    REQUIRE(showBoard(b) == "Todo:\n[1] Task 1\n[2] Task 2\nDone:\n");
    b.toDone(1);

    REQUIRE(showBoard(b) == "Todo:\n[2] Task 2\nDone:\n[1] Task 1\n");

}