#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-21 23:09:28
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import easygui as g

title = '打开文本文件增强版'

try:
    openf = None
    openf = g.fileopenbox('您要打开啥', title, default=openf)

    with open(openf) as file:
        text = file.read()
        new_text = g.textbox('%s 的内容如下：' % openf, title, text)

    if (new_text is not None) and (new_text != text):
        choices = ['覆盖保存', '放弃保存', '另存为']
        decision = g.buttonbox('警告！检测到文件已被修改。请问是否保存？', title, choices)
        if decision == '放弃保存':
            raise TypeError
        elif decision == '覆盖保存':
            with open(openf, 'w') as file:
                file.write(new_text)
        else:
            save_file = g.filesavebox('另存为', title)
            with open(save_file, 'w') as file:
                file.write(new_text)
        g.msgbox('%s成功！' % decision, title)
    else:
        raise TypeError

except (TypeError, PermissionError):
    g.msgbox('感谢使用！', title)
