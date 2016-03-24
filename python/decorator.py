#!/usr/bin/python3
#-*- coding:utf-8 -*-
from functools import wraps

def xxx(func):
    @wraps(func)
    def my(n):
        func(n*100)
        return
    return my

@xxx
def abc(n):
    print(n)

if __name__ == '__main__':
    abc(10)
    abc.__wrapped__(10)
    xx = abc.__wrapped__
    xx(1234)
