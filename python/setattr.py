#!/usr/bin/python3
#-*- coding:utf-8 -*-
from functools import wraps

class XXX(object):
    def __init__(self):
        pass

    def __setattr__(self, what, to_what):
        print('type {0} value {1}'.format(type(what), what))
        print('type {0} value {1}'.format(type(to_what), to_what))
        self.__dict__[what] = to_what*10

if __name__ == '__main__':
    x = XXX()
    x.a = 10
    print(x.a)
