#pragma once

#include <string>
#include <vector>
#include "Task.hpp"

class Board{
    private:
        int _nextId;

    public:
        std::vector<Task> _todo;
        //std::vector<Task> _done;

        Board();

        void addTodo(std::string description);
        //void toDone(int id);
};