#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-04 12:03:38
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class C:

    def __getattribute__(self, name):
        return super().__getattribute__(name)

    def __getattr__(self, name):
        print('该属性不存在！')


c = C()
c.x = 3
print(c.x)
c.y
print(c.y)
