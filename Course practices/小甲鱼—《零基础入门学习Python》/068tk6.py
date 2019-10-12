# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 068tk6.py
@time: 2017/7/27 23:37

控制Scale滑块的精度和步长
"""


from tkinter import *


def main():
    root = Tk()

    s1 = Scale(root, from_=0, to=42, tickinterval=5, resolution=5, length=200)
    s1.pack()
    s2 = Scale(root, from_=0, to=200, orient=HORIZONTAL, tickinterval=10, length=600)
    s2.pack()

    # def show():
    #     print(s1.get(), s2.get())
    #
    # Button(root, text='获取位置', command=show).pack()

    mainloop()


if __name__ == '__main__':
    main()
