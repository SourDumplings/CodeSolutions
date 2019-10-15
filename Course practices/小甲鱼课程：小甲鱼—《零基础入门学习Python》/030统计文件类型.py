#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-16 22:26:05
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import os

content = input('请输入要统计的目录：')
os.chdir(content)

filelist = os.listdir()
houzhui = {}

for each in filelist:
    temp = list(os.path.splitext(each))
    if temp[1] == '':
        temp[1] = '文件夹'
    if temp[1] in houzhui:
        houzhui[temp[1]] += 1
    else:
        houzhui[temp[1]] = 1

for i in houzhui:
    print('该文件下共有类型为【%s】的文件 %d \
个' % (i, houzhui[i]))
