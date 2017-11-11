# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 071tk5.py
@time: 2017/7/31 11:22

利用canvas绘制多边形：五角星
"""


from tkinter import *
import math as m


def main():
    root = Tk()

    w = Canvas(root, width=200, height=100, background='red')
    w.pack()

    center_x = 100
    center_y = 50
    r = 50

    points = [
        # 左上点
        center_x - int(r * m.sin(2 * m.pi / 5)),
        center_y - int(r * m.cos(2 * m.pi / 5)),
        # 右上点
        center_x + int(r * m.sin(2 * m.pi / 5)),
        center_y - int(r * m.cos(2 * m.pi / 5)),
        # 左下角
        center_x - int(r * m.sin(m.pi / 5)),
        center_y + int(r * m.cos(m.pi / 5)),
        # 顶点
        center_x,
        center_y - r,
        # 右下点
        center_x + int(r * m.sin(m.pi / 5)),
        center_y + int(r * m.cos(m.pi / 5))
    ]

    w.create_polygon(points, outline='green', fill='yellow')

    mainloop()


if __name__ == '__main__':
    main()