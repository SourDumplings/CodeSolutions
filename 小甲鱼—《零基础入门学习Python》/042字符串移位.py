#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-30 13:42:05
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Nstr(str):

    def __lshift__(self, n):
        result = self[n:] + self[:n]
        return result

    def __rshift__(self, n):
        result = self[(len(self) - n):] + self[:(len(self) - n)]
        return result


a = Nstr('I love FishC.com!')
print(a << 3)
print(a >> 3)
