#!/usr/bin/python3
#-*- coding:utf-8 -*-

def xxx(m):
    """
    will call obj's __init__ in this decorator
    """
    def ff(obj):
        a = obj(m)
        def fff():
            return a
        return fff
    return ff

@xxx({'k':'v', 'xx':'yy'})
class A(object):
    def __init__(self, m):
        self.msg = m
        pass

    def sayMsg(self):
        for k, v in self.msg.items():
            print(k,v)

if __name__ == "__main__":
    a = A() # call fff() in ff() in xxx()
    a.sayMsg()
