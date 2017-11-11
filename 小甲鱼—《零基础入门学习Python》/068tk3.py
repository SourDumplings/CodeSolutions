# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 068tk3.py
@time: 2017/7/27 23:25

垂直滚动条组件
"""

from tkinter import *


def main():
    root = Tk()

    sb = Scrollbar(root)
    sb.pack(side=RIGHT, fill=Y)

    lb = Listbox(root, yscrollcommand=sb.set)

    for i in range(20):
        lb.insert(END, i)

    lb.pack(side=LEFT, fill=BOTH)

    sb.config(command=lb.yview)

    mainloop()


if __name__ == '__main__':
    main()
