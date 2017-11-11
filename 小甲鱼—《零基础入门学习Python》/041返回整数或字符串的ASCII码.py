#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-29 21:17:05
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Nint(int):

    def __new__(cls, n):
        if isinstance(n, str):
            result = 0
            for each in n:
                result += ord(each)
            return int.__new__(cls, result)
        else:
            return int.__new__(cls, n)


print(Nint(123))
print(Nint(1.5))
print(Nint('A'))
print(Nint('FishC'))
