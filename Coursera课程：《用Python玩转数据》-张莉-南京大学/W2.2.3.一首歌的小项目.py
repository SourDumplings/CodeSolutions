#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-12 19:56:13
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
3. 请完成以下文件综合编程迷你项目（提示：可以利用list的insert函数）。

(1) 创建一个文件Blowing in the wind.txt，其内容是：

How many roads must a man walk down

Before they call him a man

How many seas must a white dove sail

Before she sleeps in the sand

How many times must the cannon balls fly

Before they're forever banned

The answer my friend is blowing in the wind

The answer is blowing in the wind

(2) 在文件头部插入歌名“Blowin’ in the wind”

(3) 在歌名后插入歌手名“Bob Dylan”

(4) 在文件末尾加上字符串“1962 by Warner Bros. Inc.”

(5) 在屏幕上打印文件内容
'''

def insert_line(lines):
    lines.insert(0, "Blowin' in the wind\n")
    lines.insert(1, "Bob Dylan\n")
    lines.append("1962 by Warner Bros. Inc.")
    return ''.join(lines)

with open('W2.Blowing in the wind.txt', 'r+') as f:
    lines = f.readlines()
    string = insert_line(lines)
    print(string)
    f.seek(0)
    f.write(string)
