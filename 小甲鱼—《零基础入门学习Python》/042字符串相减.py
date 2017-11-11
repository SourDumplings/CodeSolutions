#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-30 13:31:32
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class Nstr(str):

    def __sub__(self, other):
        result = ''
        for each in self:
            if each not in other:
                result += each
        return result


a = Nstr('I love FishC.com!iiiiiiii')
b = Nstr('i')
print(a - b)
