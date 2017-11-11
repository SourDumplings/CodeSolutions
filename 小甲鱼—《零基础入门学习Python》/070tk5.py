# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 070tk5.py
@time: 2017/7/29 16:59

实现撤销和恢复操作
"""


from tkinter import *


def main():
    root = Tk()

    text = Text(root, width=30, height=5, undo=True, autoseparators=False)
    text.pack()

    text.insert(INSERT, 'I love FishC.com')

    def callback(event):
        text.edit_separator()

    text.bind('<Key>', callback)

    def show():
        text.edit_undo()

    Button(root, text='撤销', command=show).pack()

    mainloop()


if __name__ == '__main__':
    main()
