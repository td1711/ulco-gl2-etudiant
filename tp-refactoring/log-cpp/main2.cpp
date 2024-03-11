#include <fstream>
#include <functional>
#include <iostream>

using logFunc_t = std::function<void(const std::string &)>;

int add3(int n) {
    return n+3;
}

int mul2(int n) {
    return n*2;
}

int mycomputefile(logFunc_t logF, int v0){
    logF("add3 " + std::to_string(v0));
    const int v1 = add3(v0);
    logF("mul2 " + std::to_string(v1));
    const int v2 = add3(v1);
    return v2;
}

void cout(std::string s){
    std::cout << s << std::endl;
}

void file(std::string s){
    std::fstream of("message.txt");
    of << s << std::endl;
}

int main() {
    std::cout << "this is log-cpp" << std::endl;

    
    mycomputefile(cout, 18);
    mycomputefile(file, 18);

    return 0;
}

