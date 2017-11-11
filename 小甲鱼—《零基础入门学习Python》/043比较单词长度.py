#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-30 22:21:35
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Word(int):

    def __new__(cls, other):
        if ' ' in other:
            index = other.find(' ')
            other = other[:index]
        return int.__new__(cls, len(other))


a = Word('fuck')
b = Word('you')
c = Word('suck my dick')
d = Word('apple')

print(a == c)
print(a >= c)
print(a < d)
print(c > d)
print(b <= a)
print(a != b)
