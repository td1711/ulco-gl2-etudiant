#include <iostream>
#include <vector>

class ReportStdout {
    public:
        void reportStdout(Board b) {
            for (const std::string & item : b.getItems())
                std::cout << item << std::endl;
            std::cout << std::endl;
        }
};