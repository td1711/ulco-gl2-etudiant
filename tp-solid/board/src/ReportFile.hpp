#include <iostream>
#include <vector>
#include <fstream>

class ReportFile {
    private:
        std::ofstream _ofs;

    public:
        ReportFile(const std::string & filename) : _ofs(filename){}

        void report(Board b) {
            for (const std::string & item : b.getItems())
                _ofs << item << std::endl;
            _ofs << std::endl;
        }
};