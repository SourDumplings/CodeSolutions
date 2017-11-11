# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 076tk4.py
@time: 2017/8/8 23:32

grid组件，跨行跨列显示
"""

from tkinter import *


def main():
    root = Tk()

    Label(root, text='用户名').grid(row=0, sticky=W)
    Label(root, text='密码').grid(row=1, sticky=W)

    photo = PhotoImage(file='18.gif')
    Label(root, image=photo).grid(row=0, column=2, rowspan=2, padx=5, pady=5)

    Entry(root).grid(row=0, column=1)
    Entry(root, show='*').grid(row=1, column=1)

    Button(text='提交', width=10).grid(row=2, columnspan=3, pady=5)

    mainloop()


if __name__ == '__main__':
    main()
