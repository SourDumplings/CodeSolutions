# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 072tk1.py
@time: 2017/8/1 23:48

利用canvas构建一个画板工具
"""

from tkinter import *


def main():
    root = Tk()

    w = Canvas(root, width=400, height=200)
    w.pack()

    def paint(event):
        x1, y1 = (event.x - 1), (event.y - 1)
        x2, y2 = (event.x + 1), (event.y + 1)
        w.create_oval(x1, y1, x2, y2, fill='red')

    w.bind('<B1-Motion>', paint)

    Label(root, text='按住鼠标左键并移动，开始绘制你的理想蓝图吧。。。').pack(side=BOTTOM)

    mainloop()


if __name__ == '__main__':
    main()
