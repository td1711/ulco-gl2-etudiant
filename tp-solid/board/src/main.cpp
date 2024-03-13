
#include "Board.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"


void testBoard(Board & b) {
    std::cout << b.getTitle() << std::endl;
    b.add("item");
    b.add("item");

    ReportStdout Rs;
    ReportFile Rf("tmp.txt");
    
    Rs.reportStdout(b);
    Rf.report(b);
}

int main() {
    Board b1(0);
    testBoard(b1);

    return 0;
}

