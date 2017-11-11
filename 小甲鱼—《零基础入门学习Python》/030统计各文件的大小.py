#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-16 22:53:32
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import os

content = input('请输入要统计的目录：')
os.chdir(content)

filelist = os.listdir()
size = {}

for each in filelist:
    size[each] = os.path.getsize(each)
    print('%s 【%s Bytes】' % (each, size[each]))
