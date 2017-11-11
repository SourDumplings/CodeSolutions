#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-16 13:57:07
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import urllib.request


with open('E:\\小甲鱼—《零基础入门学习Python》\\053论一只爬虫的自我修养\\urls.txt') as urls:
    count = 0
    for each_line in urls:
        count += 1
        content = str(urllib.request.urlopen(each_line).read())
        with open('E:\\小甲鱼—《零基础入门学习Python》\\053论一只爬虫的自我修养\\url%d.txt'
                  % count, 'w') as url:
            url.write(content)
