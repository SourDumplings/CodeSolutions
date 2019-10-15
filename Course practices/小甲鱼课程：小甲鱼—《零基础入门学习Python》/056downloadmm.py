# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 056downloadmm.py
@time: 2017/7/20 22:06

从煎蛋网上下载妹子图，每天运行一次可以爬下来pages张新的妹子图，将第74行的#comments去掉就可以使用代理
"""


import urllib.request as r
import os


def url_open(url):
    req = r.Request(url)
    req.add_header('User-Agent', 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) '
                                 'Chrome/59.0.3071.115 Safari/537.36')
    response = r.urlopen(url)
    html = response.read()
    # print(url)
    return html


def get_page(url):
    html = url_open(url).decode('utf-8')

    a = html.find('current-comment-page') + 23
    b = html.find(']', a)

    # print(html[a:b])
    return html[a:b]


def find_imgs(url):
    html = url_open(url).decode('utf-8')
    img_addrs = []

    a = html.find('img src=')

    while a != -1:
        b = html.find('.jpg', a, a+255)
        if b != -1:
            img_addrs.append('http://' + html[a+11:b+4])
        else:
            b = a + 9
        a = html.find('img src=', b)

    # for each in img_addrs:
    #     print(each)
        return img_addrs


def save_imgs(folder, img_addrs):
    for each in img_addrs:
        # print(each)
        filename = each.split('/')[-1]
        with open(filename, 'wb') as f:
            img = url_open(each)
            f.write(img)


def download_mm(folder='ooxx', pages=10):
    os.mkdir(folder)
    os.chdir(folder)

    url = 'http://jandan.net/ooxx/'
    page_num = int(get_page(url))

    for i in range(pages):
        page_num -= i
        page_url = url + 'page-' + str(page_num) + '#comments'
        img_addrs = find_imgs(page_url)
        save_imgs(folder, img_addrs)


if __name__ == '__main__':
    download_mm()