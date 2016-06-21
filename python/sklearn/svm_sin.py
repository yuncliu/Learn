#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm

x = np.random.rand(1000, 2)
x[:, 0] = x[:, 0] * 10

y = [ 1 if np.sin(i) > j else 0 for [i, j] in x]
s = svm.SVC()
s.fit(x, y)

"""
以0.1作间隔，得到平面上的网格，计算每个网格上每个点的预测值
"""
x_grid, y_grid = np.meshgrid(np.arange(0, 10.1, 0.1), np.arange(0, 2.1, 0.1))
grid_points = np.c_[x_grid.ravel(), y_grid.ravel()]

"""
这个得到的预测值是一个数组，reshape成和网格形状一样
"""
y_predicted = s.predict(grid_points)
y_predicted = y_predicted.reshape(x_grid.shape)

"""
以预测值为值画等高线
"""
plt.contourf(x_grid, y_grid, y_predicted, cmap = plt.cm.Paired, alpha=0.1)

"""
把样本上的点全画出来
"""
plt.scatter(x[:, 0],x[:, 1], c=y, cmap=plt.cm.Paired)
plt.show()
