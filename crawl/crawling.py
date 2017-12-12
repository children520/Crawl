#-*- encoding:UTF-8 -*-
import urllib2
import re
import urlparse
import robotparser

import datetime

max_errors=5
num_errors=0
rp=robotparser.RobotFileParser()

#设置访问次数为2次
def download(url,user_agent='wssp',proxy=None,num_retries=2):
    print 'downloading',url
    headers={'User-agent':user_agent}
    #设置用户代理
    request=urllib2.Request(url,headers=headers)
    #支持代理
    opener=urllib2.build_opener()
    if proxy:
        proxy_params={urlparse.urlparse(url).scheme:proxy}
        opener.add_handler(urllib2.ProxyHandler(proxy_params))
    try:
        html=urllib2.urlopen(url).read()
    except urllib2.URLError as e:
        print 'downloading error',e.reason
        html=None
        if hasattr(e,'code') and 500<=e.code<600:
            return download(url,num_retries-1)
    return html
def crawl_sitmap(url):
    sitmap=download(url)
    links=re.findall('<loc>(.*?)</loc>',sitmap)
    for link in links:
        html=download(url)

def link_crawler(seed_url,link_regex):
    max_depth=2
    seen={}

    user_agent='GoodCraweler'
    crawl_quene=[seed_url]
    seen=set(crawl_quene)
    while crawl_quene:
        url=crawl_quene.pop()
    if rp.can_fetch(user_agent,url):
        html=download(url)
        depth=seen[url]
        if depth!=max_depth:
            for link in get_links(html):
                if re.match(link_regex,link):
                    #获取绝对链接
                    link=urlparse.urljoin(seed_url,link)
                    #检验链接是否存在
                    if link not in seen:
                        seen[link]=depth+1
                        seen.add(link)
                        crawl_quene.append(link)
    else:
        print 'Block by robot.txt:',url
def get_links(html):
    webpage_regex=re.compile('<a[^>]+href=["\'](.*?)["\']',re.IGNORECASE)
    return webpage_regex.findall(html)
#下载限速
class Throttle:
    def __init__(self,delay):
        self.delay=delay
        self.domains={}
    def wait(self,url):
        domain=urlparse.urlparse(url).netloc
        last_accessed=self.domains.get(domain)
        if self.delay>0 and last_accessed is not None:
            sleep_secs=self.delay-(datetime.datetime.now()-last_accessed).seconds
            if sleep_secs>0:
                datetime.time.sleep(sleep_secs)
        self.domains[domain]=datetime.datetime.now()
'''
#加载robot.txt文件
rp.set_url('http://www.baidu.com/robots.txt')
rp.read()
url='http://www.baidu.com'
user_agent='BadCrawler'
#给指定的用户是否允许访问网页
rp.can_fetch(user_agent,url)

import itertools
for page in itertools.count(1):
    url='http://example.webscraping.com/view/-%d' %page
    html=download(url)
    if html is None:
        num_errors+=1
        if num_errors==max_errors:
            break
    else:
        num_errors=0
'''