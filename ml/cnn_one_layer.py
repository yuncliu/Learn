#!/usr/bin/env python3
# -*- coding: utf-8 -*-
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets('MNIST_data', one_hot=True)
import tensorflow as tf
sess = tf.InteractiveSession()

def weight_variable(shape):
    initial = tf.truncated_normal(shape, stddev=0.1)
    return tf.Variable(initial)

def bias_variable(shape):
    initial = tf.constant(0.1, shape=shape)
    return tf.Variable(initial)

def conv2d(x, W):
    return tf.nn.conv2d(x, W, strides=[1, 1, 1, 1], padding='SAME')

def max_pool_2x2(x):
    """
    aftter this function. the shape of the matrix will be only half
    eg: 8*8 -> 4*4
    """
    return tf.nn.max_pool(x, ksize=[1, 2, 2, 1], strides=[1, 2, 2, 1], padding='SAME')

x = tf.placeholder(tf.float32, [None, 784], name="XInput")
y_ = tf.placeholder(tf.float32, [None, 10], name="YInput")

W_conv1 = weight_variable([5, 5, 1, 32])
x_image = tf.reshape(x, [-1,28,28,1])
conv_1 = conv2d(x_image, W_conv1) #28, 28, 32
print(conv_1.get_shape())

"""
h_pool1 shape is 14 * 14 * 32
"""
h_pool1 = max_pool_2x2(conv2d(x_image, W_conv1))
#h_pool1_relu = tf.nn.relu(h_pool1)
print(h_pool1.get_shape()) #14, 14, 32

W_fc1 = weight_variable([14 * 14 * 32, 1024])
h_pool2_flat = tf.reshape(h_pool1, [-1, 14*14*32])
h_fc1 = tf.nn.relu(tf.matmul(h_pool2_flat, W_fc1))

W_fc2 = weight_variable([1024, 10])
y_conv=tf.nn.softmax(tf.matmul(h_fc1, W_fc2))

cross_entropy = -tf.reduce_sum(y_*tf.log(y_conv))
train_step = tf.train.AdamOptimizer(1e-4).minimize(cross_entropy)
correct_prediction = tf.equal(tf.argmax(y_conv,1), tf.argmax(y_,1))
accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))

writer = tf.train.SummaryWriter("cnn_one_layer.log", sess.graph)
tf.scalar_summary("cross_entropy", cross_entropy)
merged = tf.merge_all_summaries()

sess.run(tf.initialize_all_variables())
for i in range(20000):
    batch = mnist.train.next_batch(50)
    if i%100 == 0:
        train_accuracy = accuracy.eval(feed_dict={ x:batch[0], y_: batch[1]})
        print("step %d, training accuracy %g"%(i, train_accuracy))
        _, summary = sess.run([train_step, merged], feed_dict={x: batch[0], y_: batch[1]})
    if i%10 == 0:
        writer.add_summary(summary, i)


print("test accuracy %g"%accuracy.eval(feed_dict={ x: mnist.test.images, y_: mnist.test.labels}))
