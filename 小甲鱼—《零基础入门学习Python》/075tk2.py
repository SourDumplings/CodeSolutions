# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 075tk2.py
@time: 2017/8/8 17:29

从一系列固定的值中提出值的组件
"""

from tkinter import *


def main():
    root = Tk()

    w = Spinbox(root, from_=0, to=10)
    w.pack()

    mainloop()


if __name__ == '__main__':
    main()