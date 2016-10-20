#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys
import time
import urllib.request
import re
import os
from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5 import QtCore

def myformat(s):
    while s.find('<') != -1:
        i=s.find('<')
        j=s.find('>')
        s = s[:i]+s[j+1:]

    while s.find('&amp') != -1:
        i=s.find('&amp')
        s = s[:i]+s[i+4:]

    while s.find('&nbsp') != -1:
        i=s.find('&nbsp')
        s = s[:i]+s[i+5:]

    while s.find('&lt') != -1:
        s = s[:s.find('&lt')]+s[s.find('&lt')+len('&lt'):]

    return s

def translate(word):
    proxy_support = urllib.request.ProxyHandler({'http':'10.159.32.155:8080'})
    opener = urllib.request.build_opener(proxy_support)
    urllib.request.install_opener(opener)
    url = 'http://dict.baidu.com/s?wd=' + word
    print(url)
    response = urllib.request.urlopen(url)
    html = response.read().decode('utf-8')
    """print(html)"""
    response.close()
    result = "##"
    re_soundmark = re.compile('英.*?<b lang="EN-US" xml:lang="EN-US">(.*?)</b>')                                    
    soundmark = re_soundmark.findall(html)
    print(soundmark)
    if not soundmark:
        result += ' '.join(word) + '\n'
    else:
        result += ' '.join(word) + '\n英:' + soundmark[0]

    re_soundmark = re.compile('美.*?<b lang="EN-US" xml:lang="EN-US">(.*?)</b>')                                    
    soundmark = re_soundmark.findall(html)
    if not soundmark:
        result += ' '.join(word) +'\n'
    else:
        result += "  美:" + soundmark[0] + '<br />\n'

    re_colines = re.compile('<span class="collins-cnmeans">(.*?)</span><span>(.*?)</span>')
    colines = re_colines.findall(html)
    for k, v in colines:
        result += k+'<br />\n'
        result += myformat(v) + '<br />\n'

    re_meaning = re.compile('<p><strong>(.*?)</strong><span>(.*?)</span></p>')
    meanings = re_meaning.findall(html)

    for k ,v in meanings:
        result += myformat(k) + myformat(v) +'<br />\n'
 
    re_statement = re.compile('<li><p>(.*?)</p><p>(.*?)</p></li>')
    statements = re_statement.findall(html)
    i=0
    for k ,v in statements:
        if i >= 5:
            break
        result += myformat(k)+myformat(v)+'<br />\n'
        i=i+1

    return result

class WorkThread(QtCore.QThread):
    trigger = QtCore.pyqtSignal(str)
    word = ""
    def __init__(self):
        super(WorkThread, self).__init__()

    def run(self):
        print("run\n")
        x = translate(self.word)
        self.trigger.emit(x)

class Example(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle('Dict')
        self.resize(300, 200)
        self.add_layout()
        self.show()
        self.worker = WorkThread()
        self.worker.trigger.connect(self.callback)

    def add_layout(self):
        mainlayout = QVBoxLayout()

        search_bar = QHBoxLayout()
        self.t = QTextEdit()
        self.t.setFixedHeight(30)
        self.submit = QPushButton('Submit')
        self.submit.setFixedHeight(30)
        self.submit.clicked.connect(self.submit_clicked)

        search_bar.addWidget(self.t)
        search_bar.addWidget(self.submit)

        display_layout = QVBoxLayout()
        self.display = QLabel()
        #display.setText('xxx')
        #display.setMinimumHeight(10)
        #display.setStyleSheet('background: red')
        self.display.setAlignment(QtCore.Qt.AlignTop)
        display_layout.addWidget(self.display)
        g = QGroupBox('out')
        g.setLayout(display_layout)


        mainlayout.addLayout(search_bar)
        mainlayout.addWidget(g)
        self.setLayout(mainlayout)

    def submit_clicked(self, sender):
        print(sender)
        print(type(sender))
        print(self.sender().text())
        self.worker.word = self.t.toPlainText()
        print(self.worker.word)
        self.worker.start()

    def callback(self, text):
        print(text)
        self.display.setText(text)

if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())
