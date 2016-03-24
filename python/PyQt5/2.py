#!/usr/bin/env python3
# -*- coding: utf-8 -*
"""Button handle operation which take a lot of time to another thread.
Then waiting reault"""
from PyQt5.QtWidgets import *
from PyQt5.QtCore import *
import time
import sys

class WorkThread(QThread):
    trigger = pyqtSignal(str)
    def __init__(self):
        super(WorkThread, self).__init__()

    def run(self):
        print("run\n")
        time.sleep(1)
        self.trigger.emit("HellowSignal")

class MyWindow(QWidget):

    def __init__(self):
        super(MyWindow, self).__init__()
        self.button1 = QPushButton("One")
        self.button2 = QPushButton("StartThread")
        self.label1 = QLabel()
        self.layout = QGridLayout()
        self.layout.addWidget(self.button1)
        self.layout.addWidget(self.button2)
        self.layout.addWidget(self.label1)
        self.setLayout(self.layout)
        self.resize(200,200)
        self.button1.clicked.connect(self.ButtonCallBack)
        self.button2.clicked.connect(self.StartWorkInAThread)
        self.w = WorkThread()
        self.w.trigger.connect(self.Stop)

    def ButtonCallBack(self, e):
        print(e)
        print(type(self))
        print(self.sender().text())

    def StartWorkInAThread(self, e):
        self.w.start()
        print("start work\n")

    def Stop(self, text):
        print("stop\n")
        print(text)
        print(self.sender().isFinished())
        self.label1.setText(text)

if __name__== '__main__':
    app = QApplication(sys.argv)
    w = MyWindow()
    w.show()
    sys.exit(app.exec_())
