#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-14 20:00:48
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


def PrintLine(file_name, start, end):
    file = open(file_name)
    line_num = 1

    if (start != '') or (end != ''):
        start_words = '第' + start + '行'
        end_words = '第' + end + '行'
    if start == '':
        start_words = '开始'
        start = 1
    if end == '':
        end_words = '末尾'
        end = 0

    print('文件 %s %s 到 %s 的内容如下：' % (file_name, start_words, end_words))
    if end == 0:
        while True:
            line = file.readline()
            if line_num >= int(start):
                print(line)
            line_num += 1
            if line == '':
                break

    else:
        while True:
            line = file.readline()
            if line_num >= int(start):
                print(line)
            line_num += 1
            if line_num > int(end):
                break

    file.close()


file_name = input('请输入要打开的文件：')
temp = input('请输入要显示的行数【格式如 13:21 或 :21 或 21: 】')
start, end = temp.split(':')
PrintLine(file_name, start, end)
