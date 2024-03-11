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

int mycomputefile(std::ostream &o, int v0){
    o << "add3 " + std::to_string(v0) << std::endl;
    const int v1 = add3(v0);
    o << "mul2 " + std::to_string(v1) << std::endl;
    const int v2 = add3(v1);
    return v2;
}

int main() {
    std::cout << "this is log-cpp" << std::endl;

    mycomputefile(std::cout, 18);

    std::ofstream of;
    of.open("message.txt");
    mycomputefile(of, 18);

    return 0;
}

