# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 076tk5.py
@time: 2017/8/8 23:37

place 布局管理器，子组件在父组件的中间
"""

from tkinter import *

def main():
    root = Tk()

    photo = PhotoImage(file='18.gif')
    Label(root, image=photo).pack()

    def callback():
        print('正中靶心！')

    Button(root, text='点我', command=callback).place(relx=0.5, rely=0.5, anchor=CENTER)

    mainloop()


if __name__ == '__main__':
    main()