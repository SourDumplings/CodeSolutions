# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 066tk4.py
@time: 2017/7/25 15:38

这一行开始写关于本文件的说明与解释
"""

from tkinter import *


def main():
    root = Tk()

    LAGS = [
        ('Python', 1),
        ('Perl', 2),
        ('Ruby', 3),
        ('Lua', 4)]

    v = IntVar()
    v.set(1)

    for lang, num in LAGS:
        b = Radiobutton(root, text=lang, variable=v, value=num, indicatoron=False)
        b.pack(fill=X)

    mainloop()


if __name__ == '__main__':
    main()
