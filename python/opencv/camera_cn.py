#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import cv2
import numpy as np
import tensorflow as tf

camera = cv2.VideoCapture(0)
sess = tf.Session()
while True:
    ret, frame = camera.read()
    #frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    (height, width, channel) = frame.shape
    input = tf.to_float(tf.reshape(frame, [1, height, width, channel]))
    filter = tf.ones(shape=(3, 3, 3, 3), dtype=tf.float32)
    filter = filter* 0.0001
    conv_op = tf.nn.conv2d(input, filter, [1, 3, 3, 1], "SAME")

    # compute avg pool in a 2*2 matrix
    pool_op = tf.nn.avg_pool(conv_op, ksize=[1,2,2,1], strides=[1,1,1,1], padding = "SAME")
    pool = sess.run(pool_op)
    pooled= np.reshape(pool, pool.shape[1:])
    cv2.imshow('hello', pooled)
    if cv2.waitKey(1) == ord('q'):
        break

camera.release()
