# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 060obtainproxyIP.py
@time: 2017/7/21 22:16

自动从代理IP的网站http://www.xicidaili.com/
上获取代理IP地址（包含端口号）并打印
"""


import urllib.request as r
import re


def open_url(url):
    req = r.Request(url)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/59.0.3071.115 Safari/537.36')
    response = r.urlopen(req)
    html = response.read().decode('utf-8')
    return html


def get_ips(html):
    ip = r'(?:(?:[0,1]?\d?\d|2[0-4]\d|25[0-5])\.){3}(?:[0,1]?\d?\d|2[0-4]\d|25[0-5])'
    iplist = re.findall(ip, html)


    for each in iplist:

        #获得端口号
        ipend = re.search(each, html).end() + 5
        post_start = html[ipend:].find('<td>')
        post_stop = html[ipend:].find('</td>')
        post = html[ipend:][(post_start+4):post_stop]

        print(each+':'+post)


if __name__ == '__main__':
    url = 'http://www.xicidaili.com/'
    get_ips(open_url(url))