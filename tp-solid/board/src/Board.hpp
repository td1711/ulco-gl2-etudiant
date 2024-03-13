#pragma once

#include "Itemable.hpp"

#include <iostream>

class Board : public Itemable {
    private:
        std::vector<std::string> _tasks;

    public:
        Board(){}

        void add(const std::string & t) {
            _tasks.push_back(t);
        }

        std::vector<std::string> getItems() const override {
            return _tasks;
        }

        virtual std::string getTitle() const override {
            return "Board";
        }

};

