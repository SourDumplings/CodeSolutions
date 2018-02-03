#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2018-01-12 14:54:25
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : https://github.com/SourDumplings
# @Version : $Id$

'''
W2
1.  “迷你爬虫编程小练习”进阶：抽取某本书的前50条短评内容并计算评分的平均值。
我试了一下《Introdution to Algorithms》
'''

import requests, re, time
from bs4 import BeautifulSoup

full_star = 50
count = 0
i = 0
sum, count_s = 0, 0
while(count < 50):
    try:
        r = requests.get('https://book.douban.com/subject/3904676/comments/hot?p=' + str(i+1))
    except Exception as err:
        print(err)
        break
    soup = BeautifulSoup(r.text, 'lxml')
    comments = soup.find_all('p', 'comment-content')
    for item in comments:
        count = count + 1
        print(count, item.string)
        if count == 50:
            break
    pattern = re.compile('<span class="user-stars allstar(.*?) rating"')
    p = re.findall(pattern, r.text)
    for star in p:
        count_s = count_s + 1
        sum += int(star) / full_star * 10
    time.sleep(5)    # delay request from douban's robots.txt
    i += 1
print(sum / count_s)
