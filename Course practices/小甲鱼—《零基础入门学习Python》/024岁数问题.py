#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-13 16:31:42
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def Age(n):
    if n == 1:
        return 10
    else:
        return Age(n - 1) + 2


print('第五个人的岁数是：%d' % Age(5))
