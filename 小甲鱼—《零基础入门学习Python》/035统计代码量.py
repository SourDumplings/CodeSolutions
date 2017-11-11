#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-22 13:00:58
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import os
import easygui as g
code_filenum = {}
code_lines = {}
code_types = ['.py', '.c', '.cpp', '.pas', '.asm']

for each_type in code_types:
    code_filenum.setdefault(each_type, 0)
    code_lines.setdefault(each_type, 0)


def CalCodeLines(file):
    lines = 0
    with open(file, encoding='utf-8') as f:
        print('正在分析文件：%s ...' % file)
        try:
            for each_lines in f:
                lines += 1
        except UnicodeDecodeError:
            pass  # 如果在打开文件那里没有encoding = 'utf-8'，便会出错，
            # 因为中文编码是gbk，会导致凡是含有中文注释的文件中的代码都不计入总行数内，导致少算了许多，用答案的例子一对比就可以发现
    return lines


def SearchCodeFile(path):
    os.chdir(path)
    all_files = os.listdir(path)
    for each_file in all_files:
        if os.path.isdir(each_file):
            SearchCodeFile(os.path.join(path, each_file))
            os.chdir(os.pardir)
        elif os.path.splitext(each_file)[1] in code_types:
            code_lines[os.path.splitext(
                each_file)[1]] += CalCodeLines(each_file)
            code_filenum[os.path.splitext(each_file)[1]] += 1


path = g.diropenbox('请选择您的代码库', '浏览文件夹')
SearchCodeFile(path)
sum_lines = sum(code_lines.values())
percent = (sum_lines / 100000) * 100

if percent >= 100:
    msg = '''您目前共累计编写了 %d 行代码。
恭喜您已完成十万行代码，请继续努力，继续学习！''' % sum_lines
else:
    msg = '''您目前共累计编写了 %d 行代码，完成进度：%.1f %%
离十万行代码还差 %d 行，请继续努力！''' % (sum_lines, percent, (100000 - sum_lines))

text = ''
for each_type in code_lines:
    text += '【%s】源文件 %d 个，源代码 %d 行\n' % \
        (each_type, code_filenum[each_type], code_lines[each_type])

g.textbox(msg, '统计结果', text)
