#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from multiprocessing import Pool

def worker(a):
    print(a)

if __name__ == "__main__":
    p = Pool(10)
    p.map(worker, range(0, 1000))
