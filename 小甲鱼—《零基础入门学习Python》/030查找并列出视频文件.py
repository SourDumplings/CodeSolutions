#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-17 21:52:23
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import os
listpath = 'E:\\小甲鱼—《零基础入门学习Python》\\030\
文件系统：介绍一个高大上的东西\\videolist.txt'
file = open(listpath, 'w')

path0 = input('请输入待查找的初始目录：')


def SearchVideo(path):
    path_list = os.listdir(path)
    os.chdir(path)
    for each in path_list:
        if os.path.isdir(each):
            SearchVideo(os.path.join(path, each))
            os.chdir(os.pardir)
        else:
            houzhui = os.path.splitext(each)[1]
            if (houzhui == '.avi') or (houzhui == '.mp4')\
                    or (houzhui == '.rmvb'):
                file.write(os.path.join(path, each) + '\n')


SearchVideo(path0)
print('完成!视频列表输出为', listpath)
file.close()
