#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-30 18:23:48
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Nstr(str):

    def __add__(self, other):
        a = 0
        b = 0
        for each in self:
            a += ord(each)
        for each in other:
            b += ord(each)
        return (a + b)

    def __sub__(self, other):
        a = 0
        b = 0
        for each in self:
            a += ord(each)
        for each in other:
            b += ord(each)
        return (a - b)

    def __mul__(self, other):
        a = 0
        b = 0
        for each in self:
            a += ord(each)
        for each in other:
            b += ord(each)
        return (a * b)

    def __truediv__(self, other):
        a = 0
        b = 0
        for each in self:
            a += ord(each)
        for each in other:
            b += ord(each)
        return (a / b)


a = Nstr('FishC')
b = Nstr('love')
print(a + b)
print(a - b)
print(a * b)
print(a / b)
