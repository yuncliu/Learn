#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import tensorflow as tf

"""
Computes a 2-D convolution given 4-D input and filter tensors.

Given an input tensor of shape [batch, in_height, in_width, in_channels] and a filter / kernel tensor of shape [filter_height, filter_width, in_channels, out_channels], this op performs the following:

Flattens the filter to a 2-D matrix with shape [filter_height * filter_width * in_channels, output_channels].
Extracts image patches from the input tensor to form a virtual tensor of shape [batch, out_height, out_width, filter_height * filter_width * in_channels].
For each patch, right-multiplies the filter matrix and the image patch vector.


input: shape [bath, in_height, in_width, in_channels]
filter: shape [filter_height, filter_width, in_channels, out_channels ?]

"SAME", keep boundary, new matrix is same with input
"VALID", ignore boundary, new matrix will be smaller
"""
input = tf.ones(shape=(1, 12, 12, 1), dtype=tf.float32)
filter = tf.ones(shape=(3, 3, 1, 1), dtype=tf.float32)
sess = tf.Session()
c = tf.nn.conv2d(input, filter, [1, 3, 3, 1], "VALID")
print(sess.run(c))

filter = tf.ones(shape=(3, 3, 1, 3), dtype=tf.float32)
c = tf.nn.conv2d(input, filter, [1, 3, 3, 1], "VALID")
print(sess.run(c))
