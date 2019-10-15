# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 076tk6.py
@time: 2017/8/8 23:41

place子组件在父组件中
"""


from tkinter import *

def main():
    root = Tk()

    Label(root, bg='red').place(relx=0.5, rely=0.5, relheight=0.75, relwidth=0.75, anchor=CENTER)
    Label(root, bg='green').place(relx=0.5, rely=0.5, relheight=0.5, relwidth=0.5, anchor=CENTER)
    Label(root, bg='blue').place(relx=0.5, rely=0.5, relheight=0.25, relwidth=0.25, anchor=CENTER)

    mainloop()


if __name__ == '__main__':
    main()