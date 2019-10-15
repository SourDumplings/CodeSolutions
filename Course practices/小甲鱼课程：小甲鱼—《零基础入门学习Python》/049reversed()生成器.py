#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-12 14:08:13
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def myRev(target):
    for i in range(len(target)):
        yield target[-i - 1]


for i in myRev('FishC'):
    print(i, end='')
