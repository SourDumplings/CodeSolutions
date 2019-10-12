# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 069tk3.py
@time: 2017/7/29 10:57

插入图片
"""


from tkinter import *

def main():
    root = Tk()

    text = Text(root, width=30, height=30)
    text.pack()

    photo = PhotoImage(file='18.gif')

    def show():
        text.image_create(END, image=photo)

    b1 = Button(text, text='点我点我', command=show)
    text.window_create(INSERT, window=b1)

    mainloop()


if __name__ == '__main__':
    main()