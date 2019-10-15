# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 076tk3.py
@time: 2017/8/8 23:24

grid管理器，用户名密码输入框
"""

from tkinter import *


def main():
    root = Tk()

    Label(root, text='用户名').grid(row=0, sticky=W)
    Label(root, text='密码').grid(row=1, sticky=W)

    Entry(root).grid(row=0, column=1)
    Entry(root, show='*').grid(row=1, column=1)

    mainloop()


if __name__ == '__main__':
    main()
