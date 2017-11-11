# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 068tk5.py
@time: 2017/7/27 23:34

获取滑块的当前位置
"""

from tkinter import *


def main():
    root = Tk()

    s1 = Scale(root, from_=0, to=42)
    s1.pack()
    s2 = Scale(root, from_=0, to=200, orient=HORIZONTAL)
    s2.pack()

    def show():
        print(s1.get(), s2.get())

    Button(root, text='获取位置', command=show).pack()

    mainloop()


if __name__ == '__main__':
    main()
