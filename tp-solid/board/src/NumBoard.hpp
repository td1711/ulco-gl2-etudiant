#include <iostream>

class NumBoard {
    protected:
        int n;
    
    public:
        NumBoard(int n) : n(n){}

        int increment(){
            n+=1;
            return n;
        }
};