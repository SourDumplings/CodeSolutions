#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-13 12:31:32
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


result = []


def get_digits(num):
    if num > 0:
        result.insert(0, num % 10)
        get_digits(num // 10)


num = int(input('请输入一个正整数：'))
get_digits(num)
print(result)
