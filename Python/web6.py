import requests
import base64

url = "http://123.206.87.240:8002/web6/"
r = requests.session()
headers = r.get(url).headers

mid = base64.b64decode(headers['flag'])
mid = mid.decode()

flag = base64.b64decode(mid.split(':')[1])
data = {'margin': flag}
print(r.post(url, data).text)