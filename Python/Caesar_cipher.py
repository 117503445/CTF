# -*- coding: utf-8 -*- 

upperDict = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
             'V', 'W', 'X', 'Y', 'Z']
lowerDict = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
             'v', 'w', 'x', 'y', 'z']

'''
凯撒密码 :
    只转换字母(包括大写小写)
参数 :
    cipher_text : 明文
    offset : 偏移量
'''


def cesar_with_letter(cipher_text, offset):
    result = ""
    for ch in cipher_text:
        if ch.isupper():
            result = result + upperDict[((upperDict.index(ch) + offset) % 26)]
        elif ch.islower():
            result = result + lowerDict[((lowerDict.index(ch) + offset) % 26)]
        elif ch.isdigit():
            result = result + ch
        else:
            result = result + ch
    return result


def print_all_result(cipher_text):
    for i in range(len(upperDict)):
        print(cesar_with_letter(cipher_text, i))


text = input("Please input the words : ")
print_all_result(text)
