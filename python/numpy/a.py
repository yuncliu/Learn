#!/usr/bin/python3
#-*- coding:utf-8 -*-
import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

if __name__ == '__main__':
    a = np.array([])
    b = np.array([])
    for i in range(0, 100):
        a = np.append(a, i)
        b = np.append(b, i)

    a = np.arange(0,100,1)

    plt.plot(a, b, '-')
    print(a)
    print(b)
    plt.savefig('test.png')
