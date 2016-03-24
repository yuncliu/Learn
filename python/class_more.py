#!/usr/bin/python3
#-*- coding:utf-8 -*-
import collections

class test(object):
    def __init__(self):
        pass

def hellow():
    print('hellow')

def print_attr(x, attr):
    if isinstance(x, object):
        if hasattr(x, attr):
            print('attr[{0}] = {1}'.format(attr, getattr(x, attr)))
        else:
            print('no attr %s'%(attr))

def class_attrs():
    x = test()
    """add attribute to an object"""
    x.a = 1
    x.__setattr__('b', 2)

    print_attr(x, 'a')
    print_attr(x, 'b')
    print_attr(x, 'c')
    delattr(x, 'b')
    print_attr(x, 'b')

    x.hellow = hellow 
    if callable(x.hellow):
        x.hellow()

    if isinstance(x, test):
        print('x is a test')

    if issubclass(test, object):
        print('test is a subclass of object')

    if issubclass(type(x.a), object):
        print('x.a is subclass of object')

    print(x.__class__)
    print(type(x))
    print(x.hellow.__class__)

def create_class_at_runtime():
    myclass = type('my', (object,), {})
    print(myclass)
    a = myclass()
    print(a)

if __name__ == '__main__':
    class_attrs()
    create_class_at_runtime()
