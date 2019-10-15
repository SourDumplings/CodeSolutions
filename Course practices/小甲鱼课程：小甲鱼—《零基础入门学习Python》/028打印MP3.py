#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-14 16:41:08
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


mp3 = open('E:\\小甲鱼—《零基础入门学习Python》\\028文件：因为懂你，所以永恒\\OpenMe.mp3')
for eachline in mp3:
    print(eachline)
mp3.close()
