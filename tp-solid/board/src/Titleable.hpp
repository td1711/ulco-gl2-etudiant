#pragma once

#include <string>
#include <vector>
#include "Itemable.hpp"

class Titleable : public Itemable{
    public:
        virtual ~Titleable() = default;
        virtual std::string getTitle() const = 0;
};

