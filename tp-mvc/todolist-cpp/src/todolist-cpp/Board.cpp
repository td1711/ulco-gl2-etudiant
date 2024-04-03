#include <todolist-cpp/Board.hpp>

Board::Board(){
    _nextId = 0;
}

void Board::addTodo(std::string description){
    Task t;
    t._id = _nextId;
    t._name = description;
    _todo.push_back(t);
}