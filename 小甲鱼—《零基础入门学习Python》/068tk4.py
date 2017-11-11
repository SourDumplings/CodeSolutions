# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 068tk4.py
@time: 2017/7/27 23:31

scale组件，滑块
"""

from tkinter import *


def main():
    root = Tk()

    Scale(root, from_=0, to=42).pack()
    Scale(root, from_=0, to=200, orient=HORIZONTAL).pack()


    mainloop()


if __name__ == '__main__':
    main()