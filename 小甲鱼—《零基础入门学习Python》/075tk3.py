# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 075tk3.py
@time: 2017/8/8 17:32

从字符串中选择
"""


from tkinter import *


def main():
    root = Tk()

    w = Spinbox(root, values=('a', 'fish', 'sourdumplings'))
    w.pack()

    mainloop()


if __name__ == '__main__':
    main()