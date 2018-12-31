#!/bin/env python3
import tkinter as tk
import threading
import queue
import time

a=threading.Thread()
a.start()

q=queue.Queue()

def worker():
    q.put('开始处理')
    time.sleep(3)
    print("worker complete")
    q.put('处理完成')


class Application(tk.Frame):
    def __init__(self, master=None):
        super().__init__(master)
        self.master = master
        self.pack()
        self.create_widgets()
        self.periodicCall()

    def periodicCall(self):
        self.master.after(200, self.periodicCall)
        while not q.empty():
            a=q.get(timeout=1)
            print(a)
            self.l['text'] = a

    def create_widgets(self):
        self.input = tk.Text(self)
        self.input.grid(row=0,columnspan=2)
        self.input['height']=1
        self.input['width']=60
        #self.input.pack(side="top")
        self.startBtn = tk.Button(self)
        self.startBtn.grid(row=1,column=0)
        self.startBtn["text"] = "Start"
        self.startBtn['width'] = '20'
        self.startBtn["command"] = self.startBtnHandle
        #self.startBtn.pack(side="bottom")
        self.quit = tk.Button(self, text="QUIT", fg="red",
                              command=self.master.destroy)
        self.quit.grid(row=1,column=1)
        self.quit['width'] = '20'
        self.l = tk.Label(self)
        self.l.grid(row=2,rowspan=2, columnspan=2)
        self.l['width']=40
        self.l['height']=40
        self['height']=10
        self['width']=20
        self['padx']=5
        self['pady']=5

    def startBtnHandle(self):
        print("Start Button Clicked")
        t=threading.Thread(target=worker)
        t.setDaemon(True)
        t.start()
        print(t.getName() + 'started')

root = tk.Tk()
app = Application(master=root)
app.master.title('Hello')
app.mainloop()
