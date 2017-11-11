# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 070tk2.py
@time: 2017/7/29 16:33

tags事件绑定
"""


from tkinter import *
import webbrowser


def main():
    root = Tk()

    text = Text(root, width=30, height=5)
    text.pack()

    text.insert(INSERT, 'I love FishC.com')

    text.tag_add('link', '1.7', '1.16')
    text.tag_config('link', foreground='blue', underline=True)

    def show_arrow_cursor(event):
        text.config(cursor='arrow')

    def show_xterm_cursor(event):
        text.config(cursor='xterm')

    def click(event):
        webbrowser.open('http://www.fishc.com')

    text.tag_bind('link', '<Enter>', show_arrow_cursor)
    text.tag_bind('link', '<Leave>', show_xterm_cursor)
    text.tag_bind('link', '<Button-1>', click)


    mainloop()

if __name__ == '__main__':
    main()