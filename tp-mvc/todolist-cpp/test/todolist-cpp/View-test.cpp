#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/View.hpp>
#include <catch2/catch.hpp>

TEST_CASE( "test View" ){
    Task t {1, "TASK"};
    std::string res = showTask(t);
    REQUIRE( res == "[1] TASK");
}