#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-10 23:18:11
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class MyRev:

    def __init__(self, target):
        self.target = target
        self.i = -1

    def __iter__(self):
        return self

    def __next__(self):
        if self.i >= -len(self.target):
            self.i -= 1
            return self.target[self.i + 1]
        else:
            raise StopIteration


myRev = MyRev('FishC')
for i in myRev:
    print(i, end='')
