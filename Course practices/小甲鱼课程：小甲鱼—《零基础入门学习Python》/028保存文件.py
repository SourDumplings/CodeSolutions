#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-14 16:44:42
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


mp3 = open('E:\\小甲鱼—《零基础入门学习Python》\\028文件：因为懂你，所以永恒\\OpenMe.mp3')
txt = open('E:\\小甲鱼—《零基础入门学习Python》\\028文件：因为懂你，所以永恒\\OpenMe.txt', 'w')

temp = ''
for each in list(mp3):
    temp += each
txt.write(temp)

mp3.close()
txt.close()
