#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-21 22:40:05
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import easygui as g

try:
    openf = None
    openf = g.fileopenbox('您要打开啥', '打开文本文件', default=openf)

    with open(openf) as file:
        text = file.read()
        g.textbox('%s 的内容如下：' % openf, '打开文本文件', text)
except (TypeError, PermissionError):
    g.msgbox('感谢使用！', '打开文本文件')
