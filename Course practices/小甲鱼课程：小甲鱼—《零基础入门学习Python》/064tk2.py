# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: tk2.py
@time: 2017/7/25 10:00

tkinter演示实例2，打招呼
"""

import tkinter as tk


def main():
    class APP:
        def __init__(self, master):
            frame = tk.Frame(master)
            frame.pack(side=tk.LEFT, padx=10, pady=10)

            self.hi_there = tk.Button(frame, text='打招呼', fg='white',
                                      command=self.say_hi, bg='black')
            self.hi_there.pack()

        def say_hi(self):
            print('hello!我是酸饺子！')

    root = tk.Tk()
    app = APP(root)

    root.mainloop()


if __name__ == '__main__':
    main()
