#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-14 21:10:08
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


file_name = input('请输入文件名：')
old = input('请输入需要被替换的单词或字符：')
new = input('替换为：')
file = open(file_name)

content = file.read()
count = content.count(old)
print('文件 %s 中共有%d个 【%s】' % (file_name, count, old))
if count == 0:
    file.close()
else:
    file.close()
    judge = input('您确定要把所有的【%s】都替换成【%s】吗？【Yes/No】\n' % (old, new))
    if judge in ['Yes', 'YES', 'yes']:
        file = open(file_name, 'w')
        content = content.replace(old, new)
        file.write(content)
        print('替换完成！')
    file.close()
