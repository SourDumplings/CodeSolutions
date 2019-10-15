# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 071tk4.py
@time: 2017/7/31 11:18

canvas绘制椭圆，原理是限定矩形画内切椭圆
"""


from tkinter import *


def main():
    root = Tk()

    w = Canvas(root, width=200, height=100)
    w.pack()

    w.create_rectangle(40, 20, 160, 80, dash=(4,4))
    w.create_oval(40, 20, 160, 80, fill='pink')
    w.create_text(100, 50, text='FishC')

    mainloop()


if __name__ == '__main__':
    main()