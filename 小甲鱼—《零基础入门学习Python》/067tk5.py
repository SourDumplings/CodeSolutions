# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 067tk5.py
@time: 2017/7/25 23:07

当Entry出现非法输入时
"""

from tkinter import *


def main():
    master = Tk()

    v = StringVar()

    def test1():
        if v.get() == "小甲鱼":
            print("正确！")
            return True
        else:
            print("错误！")
            e1.delete(0, END)
            return False

    def test2():
        print("我被调用了......")
        return True

    e1 = Entry(master, textvariable=v, validate="focusout", validatecommand=test1, invalidcommand=test2)
    e2 = Entry(master)
    e1.pack(padx=10, pady=10)
    e2.pack(padx=10, pady=10)

    mainloop()


if __name__ == '__main__':
    main()
