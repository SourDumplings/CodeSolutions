# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 065tk2.py
@time: 2017/7/25 10:52

文字在图片上方，以图片为背景
"""

from tkinter import *


def main():
    root = Tk()

    photo = PhotoImage(file='E:\\小甲鱼—《零基础入门学习Python》\\065GUI的终极选择：Tkinter2\\课堂演示\\bg.gif')
    theLabel = Label(root,
                     text = '酸饺子学Python',
                     justify=LEFT,
                     image=photo,
                     compound=CENTER,
                     font=('华文行楷',20),
                     fg='white')
    theLabel.pack()

    mainloop()


if __name__ == '__main__':
    main()