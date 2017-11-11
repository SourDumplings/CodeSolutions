# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: tk3.py
@time: 2017/7/25 15:32

测试单选
"""


from tkinter import *

def main():
    root = Tk()

    v = IntVar()

    Radiobutton(root, text='one', variable=v, value=1).pack(anchor=W)
    Radiobutton(root, text='two', variable=v, value=2).pack(anchor=W)
    Radiobutton(root, text='three', variable=v, value=3).pack(anchor=W)

    mainloop()

if __name__ == '__main__':
    main()