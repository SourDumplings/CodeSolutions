# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 067tk7.py
@time: 2017/7/25 23:22

简易加法计算器
"""

from tkinter import *


def main():
    master = Tk()

    frame = Frame(master)
    frame.pack(padx=10, pady=10)

    v1 = StringVar()
    v2 = StringVar()
    v3 = StringVar()

    def test(content):
        return content.isdigit()


    testCMD = frame.register(test)
    e1 = Entry(frame, width=10, textvariable=v1, validate="key",\
               validatecommand=(testCMD, '%P')).grid(row=0, column=0)

    Label(frame, text='+').grid(row=0, column=1)

    e2 = Entry(frame, width=10, textvariable=v2, validate="key", \
               validatecommand=(testCMD, '%P')).grid(row=0, column=2)

    Label(frame, text='=').grid(row=0, column=3)

    e3 = Entry(frame, textvariable=v3, state='readonly').grid(row=0, column=4)

    def calc():
        result = int(v1.get()) + int(v2.get())
        v3.set(result)

    Button(frame, text='计算结果', command=calc).grid(row=1, column=2, pady=5)

    mainloop()


if __name__ == '__main__':
    main()
