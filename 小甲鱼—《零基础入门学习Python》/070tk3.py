# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 070tk3.py
@time: 2017/7/29 16:47

这一行开始写关于本文件的说明与解释
"""


from tkinter import *
import hashlib

def main():
    root = Tk()

    text = Text(root, width=30, height=5)
    text.pack()

    text.insert(INSERT, 'I love FishC.com')
    contents = text.get('1.0', END)

    def getSig(contents):
        m = hashlib.md5(contents.encode())
        return m.digest()

    sig = getSig(contents)


    def check():
        contents = text.get('1.0', END)
        if sig != getSig(contents):
            print('警告，内容发生了变动!')
        else:
            print('风平浪静~')


    Button(root, text='检查', command=check).pack()

    mainloop()

if __name__ == '__main__':
    main()