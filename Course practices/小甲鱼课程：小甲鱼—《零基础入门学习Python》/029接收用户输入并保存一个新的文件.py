#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-14 18:50:56
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


file_name = input('请输入文件名：')
file = open(file_name, 'w')
print('请输入内容：')


while True:
    words = input()
    if words != 'w':
        file.write(words + '\n')
    else:
        break


file.close()
