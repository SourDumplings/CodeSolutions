# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 073tk3.py
@time: 2017/8/2 22:50

实现右键弹出菜单
"""


from tkinter import *


def main():
    root = Tk()

    def callback():
        print('你好~')

    menubar = Menu(root)
    menubar.add_command(label='撤销', command=callback)
    menubar.add_command(label='重做', command=root.quit)

    frame = Frame(root, width=512, height=512)
    frame.pack()

    def popup(event):
        menubar.post(event.x_root, event.y_root)

    frame.bind('<Button-3>', popup)

    mainloop()


if __name__ == '__main__':
    main()