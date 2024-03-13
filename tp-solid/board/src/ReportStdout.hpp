#include <iostream>
#include <vector>
#include "Reportable.hpp"

class ReportStdout : public Reportable {
    public:

        void report(Board &b) override {
            for (const std::string & item : b.getItems())
                std::cout << item << std::endl;
            std::cout << std::endl;
        }
};