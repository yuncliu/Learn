#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pylab as plt
import math

def onetest(num, p):
    """
    do num times test p, return the times of p happens
    """
    return len(np.where(np.random.random(num) >= p)[0])

def test(num, p):
    x = {}
    for i in range(10000):
        n = onetest(num, p)
        if n not in x.keys():
            x[n] = 1
        else:
            x[n] = x[n] + 1

    for key in x.keys():
        x[key] = x[key] / 10000

    return list(x.keys()), list(x.values())

def strandard(num, p):
    x = {}
    for i in range(1, num + 1):
        x[i] = (math.factorial(num) /\
        (math.factorial(i) * math.factorial(num-i))) *\
        np.power(p, i) * np.power(1 - p, num-i)

    return list(x.keys()), list(x.values())


if __name__ == "__main__":
    fig = plt.figure('hellow', figsize = (12,5))

    fig_1 = fig.add_subplot(1,2,1)
    fig_2 = fig.add_subplot(1,2,2)

    x_1, y_1 = test(100, 0.3)
    fig_1.plot(x_1, y_1)
    fig_1.set_title('test')

    x_2, y_2 = strandard(100, 0.3)
    fig_2.plot(x_2, y_2)
    fig_2.set_title('binomial')

    plt.show()
