
#include "Board.hpp"
#include "NumBoard.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"


void testBoard(Board & b) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");

    ReportStdout Rs;
    ReportFile Rf("tmp.txt");
    
    Rs.reportStdout(b);
    Rf.report(b);
}

void testNumBoard(NumBoard & b){
    std::cout << b.getTitle() << std::endl;
    b.addNum("item 1");
    b.addNum("item 2");

    ReportStdout Rs;
    ReportFile Rf("tmp.txt");
    
    Rs.reportStdout(b);
    Rf.report(b);
}

int main() {
    Board b1;
    testBoard(b1);

    NumBoard b2(0);
    testBoard(b2);
    testNumBoard(b2);

    return 0;
}

