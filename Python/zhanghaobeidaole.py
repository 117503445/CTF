import requests

c = {'isAdmin', 'true'}
res = requests.get('http://123.206.87.240:9001/cookieflag.php')
print(res.cookies[0])
res.encoding = 'UTF-8'
print(res.text)
