#!/usr/bin/python3
#-*- coding:utf-8 -*-
import logging

"""
Documents
https://docs.python.org/3/library/logging.html
https://docs.python.org/3/howto/logging.html
https://docs.python.org/3/howto/logging-cookbook.html
"""


def func():
    logging.info('log from func %s', 'hellow')

if __name__ == '__main__':
    logging.basicConfig(filename='example.log',
            level=logging.DEBUG,
            format='%(asctime)s %(levelname)s %(message)s (%(filename)s:%(lineno)d %(funcName)s)')
    func()
    logging.warning("I'm log!")
