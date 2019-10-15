# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 073tk2.py
@time: 2017/8/2 22:39

利用canvas的menu搞出下拉菜单
"""

from tkinter import *


def main():
    root = Tk()

    def callback():
        print('你好~')

    menubar = Menu(root)

    filemenu = Menu(menubar, tearoff=True)
    filemenu.add_command(label='打开', command=callback)
    filemenu.add_command(label='保存', command=callback)
    filemenu.add_separator()
    filemenu.add_command(label='退出', command=root.quit)
    menubar.add_cascade(label='文件', menu=filemenu)

    editmenu = Menu(menubar, tearoff=False)
    editmenu.add_command(label='剪切', command=callback)
    editmenu.add_command(label='拷贝', command=callback)
    editmenu.add_command(label='粘贴', command=root.quit)
    menubar.add_cascade(label='编辑', menu=editmenu)

    root.config(menu=menubar)

    mainloop()


if __name__ == '__main__':
    main()
