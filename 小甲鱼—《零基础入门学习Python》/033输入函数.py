#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-19 13:43:43
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def int_input():
    while True:
        try:
            temp = input('请输入一个整数：')
            result = int(temp)
            break
        except ValueError:
            print('出错，您输入的不是整数！')
    return result


int_input()
