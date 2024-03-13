#include <iostream>
#include "Board.hpp"

class NumBoard : public Board{
    protected:
        int n;
    
    public:
        NumBoard(int n) : n(n){}

        int increment(){
            n+=1;
            return n;
        }

        void addNum(const std::string & t) {
            add(std::to_string(increment())+"-"+t);
        }
};