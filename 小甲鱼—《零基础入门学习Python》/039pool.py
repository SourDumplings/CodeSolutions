#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-28 16:27:21
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Turtle:

    def __init__(self, x):
        self.num = x


class Fish:

    def __init__(self, x):
        self.num = x


class Pool:

    def __init__(self, x, y):
        self.turtle = Turtle(x)
        self.fish = Fish(y)

    def printnum(self):
        print('水池里共有乌龟%d只，小鱼%d条' % (self.turtle.num, self.fish.num))


pool = Pool(1, 10)
pool.printnum()
