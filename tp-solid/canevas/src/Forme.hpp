#pragma once

#include "Descriptible.hpp"

class Forme : public Descriptible{
    public:
        virtual ~Forme() = default;

        virtual double aire()const=0;

};
