#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-13 13:25:07
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def Huiwen(sentence):
    l = len(sentence)
    if l:
        if sentence[0] != sentence[l - 1]:
            print('这不是回文联！')
            return
        Huiwen(sentence[1: (l - 1)])
    else:
        print('这是回文联！')
        return


sentence = input('请输入一句话：')
Huiwen(sentence)
