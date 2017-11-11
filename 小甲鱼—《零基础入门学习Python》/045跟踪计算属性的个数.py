#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-04 12:47:02
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Counter:

    def __init__(self):
        super().__setattr__('counter', 0)

    def __setattr__(self, name, value):
        self.__dict__['counter'] += 1
        super().__setattr__(name, value)

    def __delattr__(self, name):
        self.__dict__['counter'] -= 1
        super().__delattr__(name)


c = Counter()
c.x = 1
print(c.counter)
c.y = 1
c.z = 1
print(c.counter)
del c.x
print(c.counter)
