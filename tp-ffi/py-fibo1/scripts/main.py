from mypackage.myfibo import fibo_naive, fibo_iterative

if __name__ == '__main__':

    print("fibo naive")
    for i in range(11):
        print(fibo_naive(i))

    print()
    print("fibo iterative")
    for i in range(11):
        print(fibo_iterative(i))


