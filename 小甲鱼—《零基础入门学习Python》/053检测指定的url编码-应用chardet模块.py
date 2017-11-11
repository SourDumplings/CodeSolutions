#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-16 11:13:34
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import urllib.request
import chardet

url = input('请输入URL：')
responce = urllib.request.urlopen(url).read()
code = chardet.detect(responce)['encoding']

print('该网页使用的编码是：%s' % code)
