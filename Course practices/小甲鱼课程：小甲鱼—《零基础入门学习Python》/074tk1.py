# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 074tk1.py
@time: 2017/8/8 16:59

鼠标按键的事件演示
"""

from tkinter import *


def main():
    root = Tk()

    def callback(event):
        print('点击位置:', event.x, event.y)

    frame = Frame(root, width=200, height=200)
    frame.bind('<Button-1>', callback)
    frame.pack()

    mainloop()


if __name__ == '__main__':
    main()