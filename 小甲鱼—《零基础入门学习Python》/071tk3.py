# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 071tk3.py
@time: 2017/7/31 11:15

canvas之间插入文字
"""


from tkinter import *


def main():
    root = Tk()

    w = Canvas(root, width=200, height=100)
    w.pack()

    line1 = w.create_line(0, 50, 200, 50, fill='green', width=3)
    line2 = w.create_line(100, 0, 100, 100, fill='green', width=3)
    rect1 = w.create_rectangle(40, 20, 160, 80, fill='green')
    rect2 = w.create_rectangle(65, 35, 135, 65, fill='yellow')

    w.create_text(100, 50, text='FishC')


    mainloop()


if __name__ == '__main__':
    main()