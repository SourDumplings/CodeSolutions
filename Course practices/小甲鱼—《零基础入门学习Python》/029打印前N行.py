#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-14 19:52:36
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


file_name = input('请输入要打开的文件：')
N = int(input('请输入要显示该文件前几行：'))
file = open(file_name)
print('文件 %s 的前 %d 行的内容如下：' % (file_name, N))


for each_line in range(N):
    print(file.readline())

file.close()
