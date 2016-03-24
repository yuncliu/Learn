#!/usr/bin/python3
#-*- coding:utf-8 -*-
import time
import sys
 
def progress_bar():
    bar_length=20
    for percent in range(0, 100):
        hashes = '#' * int(percent/100.0 * bar_length)
        spaces = ' ' * (bar_length - len(hashes))
        sys.stdout.write("\rPercent: [%s] %d%%"%(hashes + spaces, percent))
        sys.stdout.flush()
        time.sleep(0.1)
 
progress_bar()
