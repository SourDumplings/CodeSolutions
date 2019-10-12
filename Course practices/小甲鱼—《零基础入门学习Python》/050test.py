#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-12 22:39:06
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import const


const.NAME = 'fishC'
print(const.NAME)

try:
    const.NAME = 'I love you'
except TypeError as reason:
    print(reason)

try:
    const.name = 'FishC'
except TypeError as reason:
    print(reason)
