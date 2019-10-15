# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 069tk2.py
@time: 2017/7/29 10:54

文本中插入按钮
"""


from tkinter import *

def main():
    root = Tk()

    text = Text(root, width=30, height=5)
    text.pack()

    text.insert(INSERT, 'I love \n')
    text.insert(END, 'FishC.com')

    def show():
        print('我被点了！')

    b1 = Button(text, text='点我点我', command=show)
    text.window_create(INSERT, window=b1)

    mainloop()


if __name__ == '__main__':
    main()