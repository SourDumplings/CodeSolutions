# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 071tk1.py
@time: 2017/7/31 10:43

canvas组件
"""

from tkinter import *

def main():
    root = Tk()

    w = Canvas(root, width=200, height=100)
    w.pack()

    w.create_line(0, 50, 200, 50, fill='yellow')
    w.create_line(100, 0, 100, 100, fill='red', dash=(4, 4))
    w.create_rectangle(50, 25, 150, 75, fill='blue')


    mainloop()


if __name__ == '__main__':
    main()