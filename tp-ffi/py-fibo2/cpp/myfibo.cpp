#include <cassert>

int fiboNaive(int n) {
    assert(n => 0);
    return n < 2 ? n : fiboNaive(n-1) + fiboNaive(n-2);
}


int fiboIter(int n) {
    assert(n => 0);
    int n1 = 0;
    int n2 = 1;
    int fibo = 2;
    if(n <= 1)
        return n;
    for(int i=2; i<n+1; i++){
        fibo = n1 + n2;
        n1 = n2;
        n2 = fibo;
    }
    return fibo;

}

// TODO implement fiboIterative


#include <pybind11/pybind11.h>

PYBIND11_MODULE(myfibo, m) {

    m.def("fibo_naive", &fiboNaive);
    m.def("fibo_iter", &fiboIter);


    // TODO export fiboNaive (as fibo_naive)

    // TODO export fiboIterative (as fibo_iterative)

}

