
#include "Board.hpp"
#include "NumBoard.hpp"
#include "Reportable.hpp"
#include "ReportStdout.hpp"
#include "ReportFile.hpp"

void testBoard(Board & b, Reportable& R) {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");
   
    R.report(b);
}

void testNumBoard(NumBoard & b, Reportable& R){
    std::cout << b.getTitle() << std::endl;
    b.addNum("item 1");
    b.addNum("item 2");
    
    R.report(b);
}

int main() {
    ReportStdout Rs;
    ReportFile Rf("tmp.txt");

    Board b1;
    testBoard(b1, Rs);

    NumBoard b2(0);
  

    testBoard(b2, Rf);
    testNumBoard(b2, Rs);

    return 0;
}

