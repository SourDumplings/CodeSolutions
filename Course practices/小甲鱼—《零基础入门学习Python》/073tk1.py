# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 073tk1.py
@time: 2017/8/2 22:33

利用canvas的menu搞出菜单
"""

from tkinter import *


def main():
    root = Tk()

    def callback():
        print('你好~')

    menubar = Menu(root)
    menubar.add_command(label='hello', command=callback)
    menubar.add_command(label='quit', command=root.quit)

    root.config(menu=menubar)

    mainloop()


if __name__ == '__main__':
    main()
