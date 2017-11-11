# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 075tk4.py
@time: 2017/8/8 17:33

PanedWindow组件，允许用户自由划分空间,二窗格
"""

from tkinter import *


def main():
    m = PanedWindow(orient=VERTICAL)
    m.pack(fill=BOTH, expand=1)

    top = Label(m, text='top plane')
    m.add(top)

    bottum = Label(m, text='bottum plane')
    m.add(bottum)

    mainloop()


if __name__ == '__main__':
    main()
