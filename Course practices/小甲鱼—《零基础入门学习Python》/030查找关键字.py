#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-17 22:35:50
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import os

keyword = input('请将该脚本放入待查找的文件夹内，请输入关键字：')
order = input('请问是否需要打印关键字【%s】在文件中的具体位置？（Yes/No）\n' % keyword)
Yes = ['yes', 'Yes', 'YES']


def KeywordinLine(line, linenum):
    position = []
    start = 0
    length = len(keyword)
    while True:
        index = line.find(keyword, start)
        if index == -1:
            break
        position.append(index + 1)
        start = index + length
    print('关键字出现在第', linenum + 1, '行，第', position, '个位置。')


def KeywordinFile(filepath):
    file = open(filepath)
    content = file.read()
    linenum = 1
    if keyword in content:
        print('在文件【%s】中找到关键字【%s】' % (filepath, keyword))
        file.close()
        if order in Yes:
            file = open(filepath)
            for line in file:
                if keyword in line:
                    KeywordinLine(line, linenum)
                linenum += 1
    file.close()


def Search(path):
    path_list = os.listdir(path)
    os.chdir(path)
    for each in path_list:
        if os.path.isdir(each):
            Search(os.path.join(path, each))
            os.chdir(os.pardir)
        elif os.path.splitext(each)[1] == '.txt':
            KeywordinFile(os.path.join(path, each))
        else:
            continue


Search(os.getcwd())
