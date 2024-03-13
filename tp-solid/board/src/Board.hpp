#pragma once

#include "Itemable.hpp"
#include "NumBoard.hpp"

#include <iostream>

class Board : public Itemable, public NumBoard{
    private:
        std::vector<std::string> _tasks;

    public:
        Board(int n): NumBoard(n){}

        void add(const std::string & t) {
            _tasks.push_back(std::to_string(increment())+"-"+t);
        }

        std::vector<std::string> getItems() const override {
            return _tasks;
        }

        virtual std::string getTitle() const override {
            return "Board";
        }

};

