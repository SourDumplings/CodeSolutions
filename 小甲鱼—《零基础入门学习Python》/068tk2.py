# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 068tk2.py
@time: 2017/7/27 23:22

当选项太多了怎么办，修改height
"""


from tkinter import *


def main():
    master = Tk()

    theLB = Listbox(master, selectmode=EXTENDED, height=11)
    theLB.pack()

    for item in range(11):
        theLB.insert(END, item)

    mainloop()


if __name__ == '__main__':
    main()
