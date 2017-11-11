# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 067tk1.py
@time: 2017/7/25 22:29

演示双输入框
"""

from tkinter import *

def main():
    root = Tk()

    e = Entry(root)
    e.pack(padx=20, pady=20)

    e.delete(0, END)
    e.insert(0, '默认文本...')

    mainloop()


if __name__ == '__main__':
    main()