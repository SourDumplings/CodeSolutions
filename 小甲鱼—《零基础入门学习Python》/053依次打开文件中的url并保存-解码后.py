#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-16 14:08:57
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import urllib.request
import chardet


with open('E:\\小甲鱼—《零基础入门学习Python》\\053论一只爬虫的自我修养\\urls.txt') as urls:
    count = 0
    for each_line in urls:
        count += 1
        html = urllib.request.urlopen(each_line).read()
        code_type = chardet.detect(html)['encoding']
        if code_type == 'GB2312':
            code_type = 'GBK'
        content = html.decode(code_type, 'ignore')
        with open('E:\\小甲鱼—《零基础入门学习Python》\\053论一只爬虫的自我修养\\url%d.txt'
                  % count, 'w', encoding=code_type) as url:
            url.write(content)
