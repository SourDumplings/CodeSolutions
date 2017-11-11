# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 076tk2.py
@time: 2017/8/8 23:21

pack依次排列
"""


from tkinter import *


def main():
    root = Tk()

    Label(root, text='red', bg='red', fg='white').pack(side=LEFT)
    Label(root, text='green', bg='green', fg='black').pack(side=LEFT)
    Label(root, text='blue', bg='blue', fg='white').pack(side=LEFT)

    mainloop()


if __name__ == '__main__':
    main()