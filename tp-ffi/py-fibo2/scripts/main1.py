import myfibo
if __name__ == '__main__':

    for i in range(11):
        print(f"fibo_naive({i}) = {myfibo.fibo_naive(i)}")

    print()
    for i in range(11):
        print(f"fibo_iter({i}) = {myfibo.fibo_iter(i)}")

    # TODO print fibo_iterative(i) for i from 0 to 10

