#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-29 20:33:33
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


class FileObject:
    '给文件对象一个封装从而确认在删除时文件流关闭'

    def __init__(self, filename='sample.txt'):
        # 读写模式打开一个文件
        self.new_file = open(filename, 'r+')

    def __del__(self):
        self.new_file.close()
        del self.new_file
