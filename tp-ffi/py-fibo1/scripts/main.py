from mypackage.myfibo import fibo_naive, fibo_iterative

if __name__ == '__main__':

    for i in range(11):
        print(f"fibo_naive({i}) = {fibo_naive(i)}")

    print()
    for i in range(11):
        print(f"fibo_iterative({i}) = {fibo_iterative(i)}")


