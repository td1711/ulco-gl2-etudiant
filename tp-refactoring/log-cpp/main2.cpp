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

void cout(const std::string &s){
    std::cout << s << std::endl;
}


int main() {
    std::cout << "this is log-cpp" << std::endl;

    logFunc_t f1 = [](const std::string & str){
        std::cout << str;
    };

    std::ofstream of("message.txt");
    logFunc_t f2 = [&of](const std::string & str){
        of << str << std::endl;
    };

    
    mycomputefile(cout, 18);
    mycomputefile(f2, 18);

    return 0;
}

