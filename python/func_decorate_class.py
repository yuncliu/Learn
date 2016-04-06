#!/usr/bin/python3
#-*- coding:utf-8 -*-

def ddd(obj):
    """
    decorator with no arg
    """
    obj.msg = {1:10, 2:20}
    return obj

def xxx(d):
    """
    decorator with one arg
    not call obj's __init__ in this decorator
    """
    def f(obj):
        obj.msg = d
        return obj
    return f

@xxx({'k':'v', 'xx':'yy'})
class A(object):
    msg = {}
    def __init__(self):
        pass

    def sayMsg(self):
        for k, v in self.msg.items():
            print(k,v)

if __name__ == "__main__":
    a = A()
    print(type(a))
    a.sayMsg()
