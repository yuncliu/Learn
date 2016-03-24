#!/usr/bin/env python3
# -*- coding: utf-8 -*
from PyQt5.QtWidgets import *
import sys

class MyWindow(QWidget):

    def __init__(self):
        super(MyWindow,self).__init__()        
        button1 = QPushButton("One")
        layout = QGridLayout()
        layout.addWidget(button1)
        self.setLayout(layout)
        self.resize(200,200)
        button1.clicked.connect(self.ButtonCallBack)

    def ButtonCallBack(self, e):
        print(e)
        print(type(self))
        print(self.sender().text())

if __name__=='__main__':
    app = QApplication(sys.argv)
    w = MyWindow()
    w.show()
    sys.exit(app.exec_())
