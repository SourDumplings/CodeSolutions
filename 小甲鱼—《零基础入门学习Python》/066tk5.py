# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 066tk5.py
@time: 2017/7/25 15:45

将四个组件放到一个框架中
"""


from tkinter import *


def main():
    root = Tk()

    group = LabelFrame(root, text='最好的脚本语言是？', padx=5, pady=5)
    group.pack(padx=10, pady=10)

    LAGS = [
        ('Python', 1),
        ('Perl', 2),
        ('Ruby', 3),
        ('Lua', 4)]

    v = IntVar()
    v.set(1)

    for lang, num in LAGS:
        b = Radiobutton(group, text=lang, variable=v, value=num)
        b.pack(anchor=W)

    mainloop()


if __name__ == '__main__':
    main()
