import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import numpy as np
import myfibo


def test_func(x: int):
    return x*x


if __name__ == '__main__':

    xs = np.arange(0, 10, 1)
    ys = np.vectorize(myfibo.fibo_naive)(xs)

    fig, ax = plt.subplots()
    ax.plot(xs, ys)
    ax.set(xlabel='i', ylabel='test_func(i)')
    ax.grid()

    fig.savefig("output.png")
    plt.show()

