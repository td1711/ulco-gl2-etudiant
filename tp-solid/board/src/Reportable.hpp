#include <iostream>
#include <ostream>
#include "Board.hpp"

class Reportable {

    public:
        virtual void report(Board & b)=0;

        virtual ~Reportable()=default;
};