#!/usr/bin/env python3
import tensorflow as tf
import numpy as np
"""Basic usage of tensorflow"""

if __name__ == '__main__':
    """ learn an equation   y = ax
    y and x is know,  use alot of y and x to learn out a
    """
    a = np.array([[2, 1], [3, 1]])

    W = tf.Variable(tf.zeros([2, 2]))
    b = tf.Variable(tf.zeros([2]))

    x = tf.placeholder(tf.float32, [2, 1])
    y = tf.add(tf.matmul(W, x) , b)   # guess y = Wx + b
    y_ = tf.placeholder(tf.float32, [2, 1])

    deviation = tf.reduce_sum(tf.square(y - y_))
    train_step = tf.train.GradientDescentOptimizer(0.01).minimize(deviation)

    init = tf.initialize_all_variables()
    sess = tf.Session()
    sess.run(init)
    for i in range(10000):
        xx = np.random.rand(2,1)
        # yy = a * xx use this data to train
        yy = np.dot(a, xx)
        sess.run(train_step, feed_dict={x:xx, y_:yy })

    #W will be very close to matrix a
    print(sess.run(W))
