#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-16 10:37:58
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import urllib.request
response = urllib.request.urlopen('http://www.fishc.com')
print(response.read(300))
