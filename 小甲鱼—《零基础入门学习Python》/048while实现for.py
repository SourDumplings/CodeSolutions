#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-10 21:17:18
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


string = [0, 1, 2, 3, 4]
it = iter(string)

while True:
    try:
        print(next(it))
    except StopIteration:
        break
