# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 075tk6.py
@time: 2017/8/8 18:25

PanedWindow组件，让分割线显示出来
"""

from tkinter import *


def main():
    n1 = PanedWindow(showhandle=True, sashrelief=SUNKEN)
    n1.pack(fill=BOTH, expand=1)

    left = Label(n1, text='left plane')
    n1.add(left)

    n2 = PanedWindow(orient=VERTICAL, showhandle=True, sashrelief=SUNKEN)
    n1.add(n2)

    top = Label(n2, text='top plane')
    n2.add(top)

    bottom = Label(n2, text='bottom plane')
    n2.add(bottom)

    mainloop()


if __name__ == '__main__':
    main()
