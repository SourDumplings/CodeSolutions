#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2017-07-18 22:34:03
# @Author  : 酸饺子 (changzheng300@foxmail.com)
# @Link    : http://bbs.fishc.com/space-uid-437297.html
# @Version : $Id$


import re
import urllib.request
from http.cookiejar import CookieJar

# 豆瓣的登录url
loginurl = 'https://www.douban.com/accounts/login'
cookie = CookieJar()
opener = urllib.request.build_opener(urllib.request.HTTPCookieProcessor)

data = {
    "form_email": "your email",
    "form_password": "your password",
    "source": "index_nav"
}
data = {}
data['form_email'] = '15167177064'
data['form_password'] = 'zfz4522008'
data['source'] = 'index_nav'

response = opener.open(loginurl, urllib.parse.urlencode(data).encode('utf-8'))

# 验证成功跳转至登录页
if response.geturl() == "https://www.douban.com/accounts/login":
    html = response.read().decode()

    # 验证码图片地址
    imgurl = re.search(
        '<img id="captcha_image" src="(.+?)" alt="captcha" class="captcha_image"/>', html)
    if imgurl:
        url = imgurl.group(1)
        # 将验证码图片保存至同目录下
        res = urllib.request.urlretrieve(url, 'v.jpg')

        # 获取captcha-id参数
        captcha = re.search(
            '<input type="hidden" name="captcha-id" value="(.+?)"/>', html)

        if captcha:
            vcode = input('请输入图片上的验证码：')
            data["captcha-solution"] = vcode
            data["captcha-id"] = captcha.group(1)
            data["user_login"] = "登录"

            # 提交验证码验证
            response = opener.open(
                loginurl, urllib.parse.urlencode(data).encode('utf-8'))

            # 登录成功跳转至首页 '''
            if response.geturl() == "https://www.douban.com/":
                print('登录成功！')
