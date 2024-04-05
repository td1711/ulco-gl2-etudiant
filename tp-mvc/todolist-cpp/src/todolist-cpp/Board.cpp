#include <todolist-cpp/Board.hpp>
#include <algorithm>

Board::Board(){
    _nextId = 1;
}

void Board::addTodo(const std::string &description){
    _todo.push_back({_nextId, description});
    _nextId++;
}

void Board::toDone(int id){
    auto it = std::find_if(_todo.begin(), _todo.end(), [id](Task t){
        return t._id == id;
    });


    _todo.erase(it);
    _done.push_back(*it);
    

    
}
