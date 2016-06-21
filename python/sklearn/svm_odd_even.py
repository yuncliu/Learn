#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np
from sklearn import svm

"""
use self defined kernel function
not understand very clearly, but it works
"""

def my_kernel(x, y):
    xx = pow(-1, x)
    yy = pow(-1, y)
    return xx @ yy.T

x = [[i] for i in range(10)]
y = [ i%2 for i in range(10)]
s = svm.SVC(kernel = my_kernel)
#s = svm.SVC()
s.fit(x, y)

yy = [ s.predict([[i]]) for i in range(2000)]
yy = [i[0] for i in yy]

yy_correct = [ i%2 for i in range(2000)]

nu_error = 0

for i in range(len(yy)):
    if yy[i] != yy_correct[i]:
        nu_error = nu_error + 1

print(nu_error)

print(s.predict([[i] for i in range(10000, 10010)]))
