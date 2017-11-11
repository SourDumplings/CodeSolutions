# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 068tk1.py
@time: 2017/7/27 23:11

演示Listbox
"""

from tkinter import *


def main():
    master = Tk()

    theLB = Listbox(master, selectmode=EXTENDED)
    theLB.pack()

    for item in ['鸡蛋', '鸭蛋', '鹅蛋', '李狗蛋']:
        theLB.insert(END, item)

    theButton = Button(master, text='删除它', \
                       command=lambda x=theLB: x.delete(ACTIVE))
    theButton.pack()

    mainloop()


if __name__ == '__main__':
    main()
