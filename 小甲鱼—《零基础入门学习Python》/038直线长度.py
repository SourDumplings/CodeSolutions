#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-28 15:56:29
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import math as m


class Point:

    def __init__(self, name):
        print('请输入点 %s 的横纵坐标：' % name)
        self.x = float(input('x = '))
        self.y = float(input('y = '))

    def getX(self):
        return self.x

    def getY(self):
        return self.y


class Line():

    def __init__(self, p1, p2):
        self.delta_x = p1.x - p2.x
        self.delta_y = p1.y - p2.y

    def getLen(self):
        length = m.sqrt((self.delta_x) ** 2 + (self.delta_y) ** 2)
        return length


p1 = Point('p1')
p2 = Point('p2')
l = Line(p1, p2)
print('直线l的长度为：%.2f' % l.getLen())
