# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 055使用代理IP.py
@time: 2017/7/19 13:24

使用代理IP
"""

import urllib.request as r
import random


def main():
    url = 'http://www.whatismyip.com.tw'
    iplist = ['121.15.220.61:80', '210.38.1.132:8080', '42.51.26.79:3128']
    proxy_support = r.ProxyHandler({'http': random.choice(iplist)})
    opener = r.build_opener(proxy_support)
    opener.addheaders = [('User-Agent', 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36')]
    r.install_opener(opener)

    response = r.urlopen(url)
    html = response.read().decode('utf-8')

    print(html)

if __name__ == '__main__':
    main()
