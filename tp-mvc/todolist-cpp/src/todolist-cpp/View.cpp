#include <todolist-cpp/View.hpp>

std::string showTask(const Task &t){
    return "[" + std::to_string(t._id) + "] " + t._name;
}

std::string showBoard(const Board &b){
    std::string s = "Todo:\n";
    for(auto t : b._todo){
        s += showTask(t) + "\n";
    }
    s += "Done:\n";
    for(auto t : b._done){
        s += showTask(t) + "\n";
    }
    return s;
}