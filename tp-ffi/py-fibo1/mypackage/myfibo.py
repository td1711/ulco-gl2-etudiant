
def fibo_naive(n: int):
    assert n >= 0
    return n if n < 2 else fibo_naive(n-1) + fibo_naive(n-2)

def fibo_iterative(n):
    n1 = 1
    n2 = 1
    fibo = 2
    if(n <= 1):
        return n
    for i in range(2,n):
        fibo = n1 + n2
        n1 = n2
        n2 = fibo
    return fibo

