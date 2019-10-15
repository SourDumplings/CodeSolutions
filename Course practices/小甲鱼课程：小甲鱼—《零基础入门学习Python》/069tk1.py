# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 069tk1.py
@time: 2017/7/29 10:50

插入文本和编辑
"""


from tkinter import *

def main():
    root = Tk()

    text = Text(root, width=30, height=2)
    text.pack()

    text.insert(INSERT, 'I love \n')
    text.insert(END, 'FishC.com')

    mainloop()


if __name__ == '__main__':
    main()