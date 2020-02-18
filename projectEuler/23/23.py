import math

def isAbd(num):
    sumSoFar = 0
    for i in range(1, num//2 +1 ):
        if num % i == 0:
            sumSoFar += i
            if sumSoFar > num:
                return True
    return num < sumSoFar

li = {}
for i in range(1, 28124):
    if isAbd(i):
        print(i)
        li[i] = 0
        

def isSumOfAbd(num):
    for i in li:
        if (num - i) in li:
            return True


def run():
    ret = 0
    for i in range(1, 28124):
        print(i)
        if not isSumOfAbd(i):
            ret += i
    print(ret)

run()


