# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 070tk1.py
@time: 2017/7/29 16:22

text组件里的tag标签演示
"""

from tkinter import *


def main():
    root = Tk()

    text = Text(root, width=30, height=5)
    text.pack()

    text.insert(INSERT, 'I love FishC.com')

    text.tag_add('tag1', '1.7', '1.12', '1.14')
    text.tag_add('tag2', '1.7', '1.12')
    text.tag_config('tag1', background='yellow', foreground='red')
    text.tag_config('tag2', foreground='blue')


    mainloop()

if __name__ == '__main__':
    main()