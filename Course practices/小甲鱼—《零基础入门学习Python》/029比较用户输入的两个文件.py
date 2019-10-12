#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-14 19:25:27
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


file_name1 = input('请输入比较的头一个文件名：')
file_name2 = input('请输入比较的另一个文件名：')

file1 = open(file_name1)
file2 = open(file_name2)

count = 0
line = 1
diff_line = []

for each_line in file1:
    if each_line != file2.readline():
        count += 1
        diff_line.append(line)
    line += 1

print('两个文件共有 【%d】 处不一样：' % count)

for i in diff_line:
    print('第 %s 行不一样' % i)

file1.close()
file2.close()
