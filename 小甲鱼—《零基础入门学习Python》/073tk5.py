# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 073tk5.py
@time: 2017/8/3 22:21

点按钮出菜单，menubutton
"""


from tkinter import *


def main():
    root = Tk()

    def callback():
        print('你好~')

    mb = Menubutton(root, text='点我', relief=RAISED)
    mb.pack()

    filemenu = Menu(mb, tearoff=False)
    filemenu.add_command(label='打开', command=callback)
    filemenu.add_command(label='保存', command=callback)
    filemenu.add_separator()
    filemenu.add_command(label='退出', command=root.quit)


    mb.config(menu=filemenu)

    mainloop()


if __name__ == '__main__':
    main()