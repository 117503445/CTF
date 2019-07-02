import requests
from lxml import etree

import re

# url = 'http://123.206.87.240:8002/qiumingshan/'
# s = requests.Session()
# source = s.get(url)
# expression = re.search(r'(\d+[+\-*])+(\d+)', source.text).group()
# result = eval(expression)
# post = {'value': result}
# res=s.post(url, data=post)
# res.encoding='UTF-8'
# print(res.text)


se = requests.Session()

res = se.get('http://123.206.87.240:8002/qiumingshan/')
res.encoding = 'UTF-8'
html = etree.HTML(res.text)

r = html.xpath('//div[1]')
s = r[0].text[:-3]
d = {'value': eval(s)}
res = se.post('http://123.206.87.240:8002/qiumingshan/', data=d)
res.encoding = 'UTF-8'

print(res.text)
