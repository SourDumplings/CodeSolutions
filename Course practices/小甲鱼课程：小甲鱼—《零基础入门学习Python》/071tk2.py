# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 071tk2.py
@time: 2017/7/31 11:09

canvas组件修改其中的对象
"""

from tkinter import *


def main():
    root = Tk()

    w = Canvas(root, width=200, height=100)
    w.pack()

    line1 = w.create_line(0, 50, 200, 50, fill='yellow')
    line2 = w.create_line(100, 0, 100, 100, fill='red', dash=(4, 4))
    rect1 = w.create_rectangle(50, 25, 150, 75, fill='blue')

    w.coords(line1, 0, 25, 200, 25)
    w.itemconfig(rect1, fill='red')
    w.delete(line2)

    Button(root, text='删除全部', command=(lambda x=ALL: w.delete(x))).pack()

    mainloop()


if __name__ == '__main__':
    main()
