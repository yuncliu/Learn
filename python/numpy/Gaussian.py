# -*- coding: utf-8 -*-
#import numpy as np
import random
import matplotlib.pyplot as plt
def randomsum():
    #return np.sum([np.random.randint(10) for i in range(10)])
    return sum([random.randrange(0, 10) for i in range(10)])

def generatedata(t):
    x = dict()
    for i in range(0, t):
        a = randomsum()
        if a not in x.keys():
            x[a] = 1
        else:
            x[a] = x[a] + 1
    return x

def main():
    data = generatedata(1000000)
    x = list(data.keys())
    y = list(data.values())
    print(len(x))
    plt.figure(figsize=(8,4))
    plt.plot(x,y,label="times",color="red",linewidth=1)
    plt.xlabel("sum")
    plt.ylabel("times")
    plt.title("Gassian")
    plt.legend()
    plt.show()

if __name__ == '__main__':
    main()
