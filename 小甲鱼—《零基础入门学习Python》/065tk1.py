# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 065tk1.py
@time: 2017/7/25 10:36

用于输出一个提示18岁以下禁入的Label
"""

from tkinter import *


def main():
    root = Tk()

    textLabel = Label(root,
                      text='您所下载的内容少儿不宜，\n请满18岁以后观看！',
                      justify=LEFT,
                      padx=10)
    textLabel.pack(side=LEFT)

    photo = PhotoImage(file='E:\\小甲鱼—《零基础入门学习Python》\\065GUI的终极选择：Tkinter2\\课堂演示\\18.gif')
    imgLabel = Label(root, image=photo)
    imgLabel.pack(side=RIGHT)

    mainloop()


if __name__ == '__main__':
    main()
