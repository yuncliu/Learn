#!/usr/bin/env python3
import json
import math

from dataset import *
from tree import *

def id3(d, original_set):
    """make decision tree"""
    n = Node()
    h = d.get_highest_entropy_attr()
    n.key = h
    n.entropy = original_set.gain(n.key)
    for i in d.get_attr_values(n.key):
        nn = Node()
        t = d.get_subset_by_attr(n.key, i)
        hh = t.get_highest_entropy_attr()
        if hh is None:
            nn.parent_attr = i
            n.add_child(nn)
        else:
            nn.key = hh
            nn = id3(t, original_set)
            nn.parent_attr = i
            n.add_child(nn)

    return n

def get_result(attrs, d):
    """get result of target_attr on of each leaf node"""
    r = list()
    for i in attrs:
        print('{0}-{1}'.format(i[0], i[1]))
    for i in d.data:
        s = 0
        for j in attrs:
            if i[j[0]] == j[1]:
                s = s + 1
        if s == len(attrs):
            print('match {0} : {1}'.format(i, attrs))
            r.append(i[d.target_attr])

    """use the most frequent value of target attribute, I think
    it is possible not always all Yes or No"""
    return get_most_frequent_element(r)

def get_most_frequent_element(l):
    """get most frequent value in a list"""
    if type(l) != 'list':
        return None
    d = dict()
    for i in l:
        if i not in d.keys():
            d[i] = 1
        else:
            d[i] = d[i] + 1

    m = 0
    r = None
    for k, v in d.items():
        if v > m:
            m = v
            r = k
    return r

def training(tree, dataset, attrs = None):
    """use trainng data to traing the tree"""
    if attrs is None:
        attrs = list()
    children = tree.get_children()
    if len(children) == 0:
        """no children means this is leaf"""
        print('------------')
        for j in attrs:
            print(j)
        tree.val = get_result(attrs, d)
    else:
        for i in children:
            """not leaf, so move down"""
            attrs.append((tree.key,i.parent_attr))
            training(i, dataset, attrs)
            """pop the last value, so the last leaf will not influence current"""
            attrs.pop()
    return tree


if __name__ == '__main__':
    d = DataSet('Play_ball')
    d.load_from_file('day.json')
    t = Tree()
    nn = id3(d, d)
    t.root = nn;
    t.root = training(t.root, d)
    t.save_to_file('xxx.json')
