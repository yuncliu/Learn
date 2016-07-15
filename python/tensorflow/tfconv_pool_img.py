#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import tensorflow as tf
import cv2
img = cv2.imread('/home/liu/data/x.bmp')
print(img.shape)
(height, width, channel) = img.shape
input = tf.to_float(tf.reshape(img, [1, height, width, channel]))
filter = tf.ones(shape=(3, 3, 3, 3), dtype=tf.float32)
filter = filter* 0.1
c = tf.nn.conv2d(input, filter, [1, 3, 3, 1], "SAME")
sess = tf.Session()
conv =  sess.run(c)
print(conv.shape)
p = tf.nn.avg_pool(c, ksize=[1,2,2,1], strides=[1,1,1,1], padding = "SAME")
pool = sess.run(p)
print(pool.shape)

newimg = np.reshape(pool, pool.shape[1:])
cv2.imwrite("y.bmp", newimg)
