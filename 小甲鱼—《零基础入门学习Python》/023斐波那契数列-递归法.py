#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-13 10:22:49
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def fab(n):
    if n < 1:
        print('输入错误！')
        return -1
    elif n == 1 or n == 2:
        return 1
    else:
        return fab(n - 1) + fab(n - 2)


result = fab(20)
if result != -1:
    print('总共有 %d 对小兔崽子诞生' % result)
