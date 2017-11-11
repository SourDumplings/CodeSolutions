#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-10 21:26:12
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import time as t


class LeapYear:

    def __init__(self):
        self.year = 1

    def __iter__(self):
        return self

    def __next__(self):
        while not ((self.year % 4 == 0 and self.year % 100 != 0) or
                   (self.year % 400 == 0)):
            self.year += 1
            if self.year > int(t.strftime('%Y')):
                raise StopIteration
        temp = self.year
        self.year += 1
        return temp


leapYears = LeapYear()
for i in leapYears:
    if i >= 2000:
        print(i)
    else:
        continue
