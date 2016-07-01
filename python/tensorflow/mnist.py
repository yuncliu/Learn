#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import tensorflow as tf
import numpy as np
import struct
import time
"""
train data can be find here http://yann.lecun.com/exdb/mnist/
"""
def get_image(num):
    with open('train-images-idx3-ubyte', 'rb') as f:
        buf = f.read(16)
        magic = struct.unpack('>4i', buf)
        x = np.array([])
        for i in range(0, magic[1]):
            imagebuf = f.read(784)
            image = struct.unpack('>784B', imagebuf)
            x = np.append(x, np.array(image, dtype=np.float32)/255.0)
            if (i + 1) % num == 0:
                yield x.reshape(num, 784)
                x = np.array([])

def get_label(num):
    with open('train-labels-idx1-ubyte', 'rb') as f:
        buf = f.read(8)
        header = struct.unpack('>2i', buf)
        y = np.array([])
        for i in range(0, header[1]):
            labelbuf = f.read(1)
            label = struct.unpack('B', labelbuf)
            yy = np.zeros(10)
            yy[label] = 1.0
            y = np.append(y, yy)
            if (i + 1) % num == 0:
                yield y.reshape(num, 10)
                y = np.array([])

if __name__ == "__main__":

    # Create the model
    x = tf.placeholder(tf.float32, [None, 784])
    W = tf.Variable(tf.zeros([784, 10]))
    b = tf.Variable(tf.zeros([10]))
    y = tf.nn.softmax(tf.matmul(x, W) + b)

    # Define loss and optimizer
    y_ = tf.placeholder(tf.float32, [None, 10])
    cross_entropy = tf.reduce_mean(-tf.reduce_sum(y_ * tf.log(y), reduction_indices=[1]))
    train_step = tf.train.GradientDescentOptimizer(0.2).minimize(cross_entropy)

    sess = tf.InteractiveSession()
    tf.initialize_all_variables().run()
    i = 0
    ifb = False
    for image, label in zip(get_image(100), get_label(100)):
        sess.run(train_step, feed_dict={x: image, y_: label})

    #print(sess.run(W))
    for image, label in zip(get_image(1), get_label(1)):
        classification = sess.run(y, feed_dict={x: image})
        print('----------------')
        print(np.where(classification==classification.max()))
        print(label)
        print(np.where(label==label.max()))
        time.sleep(1)
