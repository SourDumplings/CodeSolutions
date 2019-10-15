# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 067tk4.py
@time: 2017/7/25 23:02

Entry验证输入
"""

from tkinter import *


def main():
    master = Tk()

    def test():
        if e1.get() == "小甲鱼":
            print("正确！")
            return True
        else:
            print("错误！")
            e1.delete(0, END)
            return False

    v = StringVar()

    e1 = Entry(master, textvariable=v, validate="focusout", validatecommand=test)
    e2 = Entry(master)
    e1.pack(padx=10, pady=10)
    e2.pack(padx=10, pady=10)

    mainloop()


if __name__ == '__main__':
    main()
