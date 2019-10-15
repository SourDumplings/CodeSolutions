# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 073tk7.py
@time: 2017/8/3 22:47

将许多项添加到下拉列表中,使用*解包
"""


from tkinter import *


OPTIONS = [
    'C',
    '458',
    'FF',
    'ENZO',
    'LaFerrari'
]
def main():
    root = Tk()

    variable=StringVar()
    variable.set(OPTIONS[0])

    w = OptionMenu(root, variable, *OPTIONS)
    w.pack()

    mainloop()


if __name__ == '__main__':
    main()