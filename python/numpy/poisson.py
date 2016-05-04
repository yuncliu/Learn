import numpy as np
import matplotlib.pyplot as plt
test_time = 20000
def test():
    s =  0
    for i in range(0, 1000):
        a = np.random.randint(10)
        if a == 1:
            s = s + 1
    return s

if __name__ == "__main__":
    example = [test() for i in range(0, test_time)]
    print(len(example))
    xx = {}
    for i in range(0, 1000):
        n = example.count(i)
        xx[i] = n/test_time

    x = list(xx.keys())
    y = list(xx.values())

    plt.figure(figsize=(8,4))
    plt.plot(x,y,label="times",color="red",linewidth=1)
    plt.xlabel("sum")
    plt.ylabel("times")
    plt.title("Gassian")
    plt.legend()
    plt.show()
