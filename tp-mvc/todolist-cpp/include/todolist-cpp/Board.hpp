#pragma once

#include <string>
#include <list>
#include "Task.hpp"

class Board{
    private:
        int _nextId;

    public:
        std::list<Task> _todo;
        std::list<Task> _done;

        Board();

        void addTodo(const std::string &description);
        void toDone(int id);
};