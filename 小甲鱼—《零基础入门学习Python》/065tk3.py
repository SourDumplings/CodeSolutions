# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 065tk3.py
@time: 2017/7/25 10:58

有按钮的tk1
"""

from tkinter import *


def main():

    def callback():
        var.set('扯淡！')

    root = Tk()

    frame1 = Frame(root)
    frame2 = Frame(root)

    var = StringVar()
    var.set('您所下载的内容少儿不宜，\n请满18岁以后观看！')
    textLabel = Label(frame1,
                      textvariable=var,
                      justify=LEFT,
                      padx=10)
    textLabel.pack(side=LEFT)

    photo = PhotoImage(file='E:\\小甲鱼—《零基础入门学习Python》\\065GUI的终极选择：Tkinter2\\课堂演示\\18.gif')
    imgLabel = Label(frame1, image=photo)
    imgLabel.pack(side=RIGHT)

    theButton = Button(frame2, text='我已满18周岁', command=callback)
    theButton.pack()

    frame1.pack(padx=10,pady=10)
    frame2.pack(padx=10,pady=10)

    mainloop()


if __name__ == '__main__':
    main()
