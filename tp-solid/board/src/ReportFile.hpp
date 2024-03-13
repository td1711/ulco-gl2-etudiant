#include <iostream>
#include <vector>
#include <fstream>
#include "Reportable.hpp"

class ReportFile : public Reportable{
    private:
        std::ofstream _ofs;

    public:
        ReportFile(const std::string & filename) : _ofs(filename){}

        void report(Board &b) override{
            for (const std::string & item : b.getItems())
                _ofs << item << std::endl;
            _ofs << std::endl;
        }
};