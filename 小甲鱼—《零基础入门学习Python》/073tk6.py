# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 073tk6.py
@time: 2017/8/3 22:44

实现下拉菜单，optionmenu
"""


from tkinter import *


def main():
    root = Tk()

    variable=StringVar()
    variable.set('one')

    w = OptionMenu(root, variable, 'one', 'two', 'three')
    w.pack()

    mainloop()


if __name__ == '__main__':
    main()