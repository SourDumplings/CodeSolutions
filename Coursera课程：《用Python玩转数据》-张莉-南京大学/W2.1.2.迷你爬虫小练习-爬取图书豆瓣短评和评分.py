#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-12 14:43:10
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
W2
请在豆瓣任意找一本图书，抓取它某一页的短评并进行页面解析将短评文字抽取后输出，
再对其中的评分进行抽取计算其总分。
我试着爬取了《C++ primer 第五版》豆瓣的短评和评分总和信息
'''

import requests
from bs4 import BeautifulSoup
import re

full_star = 50
sum = 0
r = requests.get('https://book.douban.com/subject/25708312/')
soup = BeautifulSoup(r.text, 'lxml')
pattern = soup.find_all('p', 'comment-content')
for item in pattern:
    print(item.string)
pattern_s = re.compile('<span class="user-stars allstar(.*?) rating"')
p = re.findall(pattern_s, r.text)
for star in p:
    sum += int(star) / full_star * 10
print(sum)
