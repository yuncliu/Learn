#!/usr/bin/python3
#-*- coding:utf-8 -*-
class xx:
    def __init__(self):
        print("init")

    def __del__(self):
        print("del")

    def __str__(self):
        return "hellow"

    def __repo__(self):
        return "xxxx"

if __name__ == '__main__':
    x = xx()
    for i in range(0, 1):
        print(i)
