# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 075tk1.py
@time: 2017/8/8 17:25

Message组件
"""

from tkinter import *


def main():
    root = Tk()
    w1 = Message(root, text='这是一则消息', width=100)
    w1.pack()

    w2 = Message(root, text='这是一\n则骇人听闻的长长长长长长长消息', width=100)
    w2.pack()

    mainloop()

if __name__ == '__main__':
    main()
