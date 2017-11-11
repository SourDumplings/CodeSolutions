# encoding: utf-8
"""
@author: 酸饺子
@contact: changzheng300@foxmail.com
@license: Apache Licence
@file: 【第一周】网络爬虫之规则.py
@time: 2017/8/24 22:07

MOOC课程
Python网络爬虫与信息提取
嵩天
【第一周】网络爬虫之规则
"""

import requests
import os

# 1.2 爬取网页的通用代码框架
# def getHTMLText(url):
#     try:
#         r = requests.get(url, timeout=30)
#         r.raise_for_status() # 如果状态不是200，引发HTTPError异常
#         r.encoding = r.apparent_encoding
#         return r.text
#     except:
#         return '产生异常'
#
# url = 'http://www.baidu.com'
# print(getHTMLText(url))


# 2.0 实例1：京东商品页面的爬取
# url = 'https://item.jd.com/3127327.html'
# try:
#     r = requests.get(url)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     print(r.text[:1000])
# except:
#     print('爬取失败')


# 2.1 实例2：亚马逊商品页面的爬取，修改headers字段
# url = 'https://www.amazon.cn/%E5%9B%BE%E4%B9%A6/dp/B01JBQJHRU/ref=sr_1_1?ie=UTF8&qid=1503623048&sr=8-1&keywords=%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84+%E9%99%88%E8%B6%8A'
# try:
#     kv = {'user-agent':'Mozilla/5.0'}
#     r = requests.get(url, headers=kv)
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     print(r.text[1000:2000])
# except:
#     print('爬取失败')


# 2.2 实例3：百度360搜索关键词提交
# keyword = 'Python'
# try:
#     # 百度搜索
#     # kv = {'wd':keyword}
#     # r = requests.get('http://www.baidu.com/s', params=kv)
#     # 360搜索
#     kv = {'q': keyword}
#     r = requests.get('http://www.so.com/s', params=kv)
#     print(r.request.url)
#     r.raise_for_status()
#     print(len(r.text))
# except:
#     print('爬取失败')


# 2.3 实例4：网络图片的爬取和存储,以二进制形式存储，也适应于视频、动画等
# url = 'http://image.nationalgeographic.com.cn/2017/0804/20170804050633818.jpg'
# root = 'F://abc//'
# path = root + url.split('/')[-1]
# try:
#     if not os.path.exists(root):
#         os.mkdir(root)
#     if not os.path.exists(path):
#         r = requests.get(url)
#         # 以二进制格式存储图片
#         with open(path, 'wb') as f:
#             f.write(r.content)
#             print('文件保存成功')
#     else:
#         print('文件已存在')
# except:
#     print('爬取失败')


# 2.4 实例5：IP地址归属地的自动查询
# url = 'http://www.ip138.com/ips138.asp?ip='
# try:
#     r = requests.get(url+'183.157.160.37')
#     r.raise_for_status()
#     r.encoding = r.apparent_encoding
#     print(r.text)
# except:
#     print('爬取失败')