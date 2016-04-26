import numpy as np
import scipy as sp
from scipy.optimize import leastsq
import matplotlib.pyplot as plt
x=np.array(range(0, 10)) * 10
y = [ i + np.random.normal(0, 50) for i in x]

def func(p, x):
    f = np.poly1d(p)
    return f(x)

def residuals(p, y, x):
    return y - func(p, x)

p0 = np.random.randn(2)
plsq = leastsq(residuals, p0, args=(y, x))
print(plsq[0])
yy = [func(plsq[0], i) for i in x]
print(yy)
plt.plot(x, y, '*')
plt.plot(x, yy, '-')
plt.show()
