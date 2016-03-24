import numpy as np
import matplotlib.pyplot as plt
#numpy's array is much more fast than python's built in list
xx = np.random.randint(10, size=(10, 10000000))
yy = np.sum(xx, axis=0)
data = dict()
for i in yy:
    if i not in data.keys():
        data[i] = 1
    else:
        data[i] = data[i] + 1
x = list(data.keys())
y = list(data.values())

plt.figure(figsize=(8,4))
plt.plot(x,y,label="times",color="red",linewidth=1)
plt.xlabel("sum")
plt.ylabel("times")
plt.title("Gassian")
plt.legend()
plt.show()
