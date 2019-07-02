import requests

for i in range(10000):
    url = 'http://123.206.87.240:8006/test/hello.php?id={}'.format(i)
    print(url)
    res = requests.get(url)
    res.encoding = 'UTF-8'

    print(res.text)
    if 'never never never give up' not in res.text:
        exit(0)
