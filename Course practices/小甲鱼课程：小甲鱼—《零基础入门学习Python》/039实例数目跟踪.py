#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-28 18:16:25
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class C:
    count = 0

    def __init__(self):
        C.count += 1  # 注意不是self.count += 1

    def __del__(self):
        C.count -= 1  # 注意不是self.count -= 1


a = C()
b = C()
print(C.count)
c = C()
print(C.count)
del a
print(C.count)
del c
print(C.count)
d = C()
a = C()
print(C.count)
