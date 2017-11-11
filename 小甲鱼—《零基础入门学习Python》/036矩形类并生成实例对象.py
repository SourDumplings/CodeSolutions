#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-23 20:25:35
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Rectangle:
    a = 5
    b = 4

    def getRect(self):
        print('这个矩形的长是：%.2f' % self.a)
        print('这个矩形的宽是：%.2f' % self.b)

    def setRect(self):
        try:
            while True:
                print('请输入矩形的长和宽。')
                self.a = float(input('长：'))
                self.b = float(input('宽：'))
                break
            else:
                print('设置成功！')
        except TypeError:
            print('输入错误！')

    def getArea(self):
        s = self.a * self.b
        print(s)


rect1 = Rectangle()
rect1.getRect()
rect1.setRect()
rect1.getRect()
rect1.getArea()
