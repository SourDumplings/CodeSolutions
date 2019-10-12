#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-20 09:59:30
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
3.2.编程练习：利用字典进行词频统计
'''

# import collections
# import copy
# s = "我 是 一个 测试 句子 ， 大家 赶快 来 统计 我 吧 ， 大家 赶快 来 统计 我 吧，大家 赶快 来 统计 我 吧 ， 重要 事情 说 三遍 ！"
# s_list = s.split()
# s_list_backup = copy.deepcopy(s_list)
# [s_list.remove(item) for item in s_list_backup if item in '，。！”“']
# print(collections.Counter(s_list))
#

s_dict = {}
s = "我 是 一个 测试 句子 ， 大家 赶快 来 统计 我 吧 ， 大家 赶快 来 统计 我 吧 ， 大家 赶快 来 统计 我 吧，重要 事情 说 三遍！"
s_list = s.split()
for item in s_list:
    if item.strip() not in "，。！“”":
        if item not in s_dict:
            s_dict[item] = 1
        else:
            s_dict[item] += 1
print(s_dict)
