#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import time
import tkinter as tk
from tkinter import ttk

class Win(object):
    def __init__(self):
        self.root = tk.Tk()
        self.root.title('hello')
        self.root.geometry("200x100")
        self.root.protocol('WM_DELETE_WINDOW', self.on_closing)


        tk.Button(self.root, text = 'hellow1',
                command = lambda : self.click('button2')).grid(row=1, column=0)
        tk.Button(self.root, text = 'hellow2',
                command = lambda : self.click('button3')).grid(row=1, column=1)

        pb = ttk.Progressbar(self.root, length=200, maximum=10)
        pb.grid(row=2,column=0,columnspan=2)
        pb.start()

    def run(self):
        self.root.mainloop()

    def hello(self):
        print('Hellow')

    def click(self, msg):
        print('Click: {0}'.format(msg))

    def on_closing(self):
        print('closing')
        self.root.destroy()

if __name__ == "__main__":
    x = Win()
    x.run()
