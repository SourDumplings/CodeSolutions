# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 060tieba.py
@time: 2017/7/21 11:36

下载贴吧中的图片
https://tieba.baidu.com/p/3563409202
"""


import urllib.request as r
import re


def open_url(url):
    req = r.Request(url)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36')
    response = r.urlopen(req)
    html = response.read().decode('utf-8')
    return html


def get_imgs(html):
    p = r'<img class="BDE_Image" src="([^"]+\.jpg)"'
    imglist = re.findall(p, html)

    for each in imglist:
        filename = each.split('/')[-1]
        r.urlretrieve(each, filename, None)
    #     print(each)


if __name__ == '__main__':
    url = 'https://tieba.baidu.com/p/3563409202'
    get_imgs(open_url(url))