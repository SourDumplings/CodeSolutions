#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-19 23:02:29
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def file_compare(file1, file2):
    with open(file1) as f1, open(file2) as f2:
        count = 0  # 统计行数
        differ = []  # 统计不一样的数量

        for line1 in f1:
            line2 = f2.readline()
            count += 1
            if line1 != line2:
                differ.append(count)
    return differ


file1 = input('请输入需要比较的头一个文件名：')
file2 = input('请输入需要比较的另一个文件名：')

differ = file_compare(file1, file2)

if len(differ) == 0:
    print('两个文件完全一样！')
else:
    print('两个文件共有【%d】处不同：' % len(differ))
    for each in differ:
        print('第 %d 行不一样' % each)
