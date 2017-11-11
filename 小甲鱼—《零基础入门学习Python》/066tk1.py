# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: tk1.py
@time: 2017/7/25 15:23

测试一下Checkbutton
"""

from tkinter import *


def main():
    root = Tk()

    v = IntVar()

    c = Checkbutton(root, text='测试一下呗',variable=v)
    c.pack()

    l = Label(root, textvariable=v)
    l.pack()

    mainloop()


if __name__ == '__main__':
    main()