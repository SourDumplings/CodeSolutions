#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-16 23:11:30
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import os

content = input('请输入待查找的目录：')
file_name = input('请输入待查找的目标文件：')


def Search(path, file_name):
    path_list = os.listdir(path)
    os.chdir(path)
    for each in path_list:
        if os.path.isdir(each):
            Search(os.path.join(path, each), file_name)
            os.chdir(path)
        else:
            if each == file_name:
                print(os.path.join(path, each))
    return


Search(content, file_name)
