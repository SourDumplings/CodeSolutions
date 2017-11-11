# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: tk2.py
@time: 2017/7/25 15:27

翻牌子程序
"""

from tkinter import *


def main():
    root = Tk()

    GIRLS = ['西施', '貂蝉', '王昭君', '杨玉环']

    v = []

    for girl in GIRLS:
        v.append(IntVar())
        b = Checkbutton(root, text=girl, variable=v[-1])
        b.pack(anchor=W)

    mainloop()


if __name__ == '__main__':
    main()
