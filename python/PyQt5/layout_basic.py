#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *

class Example(QWidget):
    
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Hellow')
        self.resize(300, 200)
        self.add_layout()
        self.show()

    def add_layout(self):
        grouplayout = QVBoxLayout()
        a1 = QCheckBox("hellow1")
        a2 = QCheckBox("hellow2")
        a3 = QCheckBox("hellow3")
        a4 = QCheckBox("hellow4")
        a5 = QCheckBox("hellow5")
        a6 = QCheckBox("hellow6")
        grouplayout.addWidget(a1)
        grouplayout.addWidget(a2)
        grouplayout.addWidget(a3)
        grouplayout.addWidget(a4)
        grouplayout.addWidget(a5)
        grouplayout.addWidget(a6)
        g = QGroupBox('xxx')
        g.setLayout(grouplayout)

        rightlayout = QVBoxLayout()
        b1 = QPushButton('Hellow1')
        l1 = QLabel()
        rightlayout.addWidget(l1)
        rightlayout.addWidget(b1)
        b1.resize(100,100)
        b1.clicked.connect(self.button_click)
        b1.released.connect(self.button_released)
        print(b1.geometry())

        mainlayout = QHBoxLayout()
        mainlayout.addWidget(g)
        mainlayout.addLayout(rightlayout)

        self.setLayout(mainlayout)

    def moveEvent(self, event):
    	print("old pos = {0} new pos = {1}".format(event.oldPos(), event.pos()))

    def resizeEvent(self, event):
    	print("old size = {0}  new size = {1}".format(event.oldSize(), event.size()))

    def button_click(self, sender):
    	print(sender)

    def button_released(self):
    	print('released')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
