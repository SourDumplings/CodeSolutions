#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-18 21:57:01
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import urllib.request as u
import easygui as g
import os

size = g.multenterbox(msg='请填写喵的尺寸', title='下载一只喵',
                      fields=['宽', '高'], values=[500, 600])
path = g.diropenbox(msg='请选择存放喵的文件夹')
file_name = os.path.join(path, 'cat_%d_%d.jpg' % (int(size[0]), int(size[1])))

req = u.Request('http://placekitten.com/%d/%d' % (int(size[0]), int(size[1])))
response = u.urlopen(req)
cat_img = response.read()

with open(file_name, 'wb') as f:
    f.write(cat_img)
