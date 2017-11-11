# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 076tk1.py
@time: 2017/8/8 23:18

布局管理，组件里填充组件
"""

from tkinter import *


def main():
    root = Tk()

    listbox = Listbox(root)
    listbox.pack(fill=BOTH, expand=True)

    for i in range(10):
        listbox.insert(END, str(i))

    mainloop()


if __name__ == '__main__':
    main()