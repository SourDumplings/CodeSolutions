#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-13 11:34:20
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def Bin(n, temp=''):
    if n // 2 == 0:
        temp += str(n % 2)
        return temp
    else:
        temp += str(n % 2)
        return Bin(n // 2, temp)


temp = b = ''
n = int(input('请输入一个十进制正整数：'))
temp = Bin(n, temp)
for each in reversed(temp):
    b += each
print('转换为二进制为：0b%s' % b)
