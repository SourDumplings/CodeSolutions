# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 074tk2.py
@time: 2017/8/8 17:04

演示键盘按键的事件
"""


from tkinter import *


def main():
    root = Tk()

    def callback(event):
        print(event.char)

    frame = Frame(root, width=200, height=200)
    frame.bind('<Key>', callback)
    frame.focus_set()
    frame.pack()

    mainloop()


if __name__ == '__main__':
    main()