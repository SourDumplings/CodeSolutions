#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-29 20:50:39
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class C2F(float):

    def __new__(cls, c=0):
        f = c * 1.8 + 32
        return float.__new__(cls, f)

    # def __init__(self, c):
    #     self.a = c
    #     print(self.a)


print(C2F(32))
