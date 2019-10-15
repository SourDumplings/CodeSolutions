# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: tk1.py
@time: 2017/7/25 9:53

这个例子用于演示tkinter1
"""


import tkinter as tk


def main():
    app = tk.Tk()
    app.title('FishC Demo')

    theLabel = tk.Label(app, text='我的第二个窗口程序！')
    theLabel.pack()

    app.mainloop()


if __name__ == '__main__':
    main()