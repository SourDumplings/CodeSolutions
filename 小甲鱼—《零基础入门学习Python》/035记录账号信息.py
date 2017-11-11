#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-06-21 21:55:38
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$

import easygui as g

try:
    while True:
        info = g.multenterbox('请填写以下信息', '账号中心-酸饺子',
                              fields=['*用户名',
                                      '*真实姓名',
                                      '固定电话',
                                      '*手机号码',
                                      'QQ',
                                      '*E-mail'])
        if (info[0] != '') and\
                (info[1] != '') and\
                (info[3] != '') and\
                (info[5] != ''):
            break
        else:
            g.msgbox('输入有误！带*的项目不能空!', '账号中心-酸饺子')
    g.msgbox('信息记录成功!')

except TypeError:
    g.msgbox('感谢使用！', '账号中心-酸饺子')
