# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 070tk4.py
@time: 2017/7/29 16:54

查找操作，如何全文搜索
"""

from tkinter import *


def main():
    root = Tk()

    text = Text(root, width=30, height=5)
    text.pack()

    text.insert(INSERT, 'I love FishC.com')

    def getIndex(text, index):
        return tuple(map(int, str.split(text.index(index), '.')))

    start = '1.0'
    while True:
        pos = text.search('o', start, stopindex=END)
        if not pos:
            break

        print('找到啦！位置是：', getIndex(text, pos))
        start = pos + '+1c'

    mainloop()


if __name__ == '__main__':
    main()
