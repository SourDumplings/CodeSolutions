# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 067tk6.py
@time: 2017/7/25 23:18

验证Entry中的额外选项
"""

from tkinter import *


def main():
    master = Tk()

    v = StringVar()

    def test(content, reason, name):
        if content == "小甲鱼":
            print("正确！")
            print(content, reason, name)
            return True
        else:
            print("错误！")
            print(content, reason, name)
            return False

    testCMD = master.register(test)
    e1 = Entry(master, textvariable=v, validate="focusout",\
               validatecommand=(testCMD, '%P', '%v', '%W'))
    e2 = Entry(master)
    e1.pack(padx=10, pady=10)
    e2.pack(padx=10, pady=10)

    mainloop()


if __name__ == '__main__':
    main()
