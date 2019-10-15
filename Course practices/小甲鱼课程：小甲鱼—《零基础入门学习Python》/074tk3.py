# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 074tk3.py
@time: 2017/8/8 17:09

获取鼠标实时位置
"""


from tkinter import *


def main():
    root = Tk()

    def callback(event):
        print('当前位置：', event.x, event.y)

    frame = Frame(root, width=200, height=200)
    frame.bind('<Motion>', callback)
    frame.pack()

    mainloop()


if __name__ == '__main__':
    main()