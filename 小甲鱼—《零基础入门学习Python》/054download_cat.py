#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-16 22:55:29
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import urllib.request


req = urllib.request.Request('http://placekitten.com/550/650')
response = urllib.request.urlopen(req)
cat_img = response.read()

with open('cat_550_650.jpg', 'wb') as f:
    f.write(cat_img)
