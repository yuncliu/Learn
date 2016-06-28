#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from sklearn import svm

x = np.array([[5, 1], [1, 5]])
y = [1, -1]
s = svm.LinearSVC()
s.fit(x, y)

x_grid, y_grid = np.meshgrid(np.arange(0, 5.1, 0.1), np.arange(0, 5.1, 0.1))
grid_points = np.c_[x_grid.ravel(), y_grid.ravel()]

y_predicted = s.predict(grid_points)
y_predicted = y_predicted.reshape(x_grid.shape)

plt.contourf(x_grid, y_grid, y_predicted, cmap = plt.cm.Paired, alpha=0.1, levels=[0, 0.5, 1])

plt.scatter(x[:, 0],x[:, 1], c=y, cmap=plt.cm.Paired)
plt.xlabel("X")
plt.ylabel("Y")
plt.axis('equal')
plt.grid(b=True, axis='both')
plt.show()
