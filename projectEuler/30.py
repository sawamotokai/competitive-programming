import random

n = [i for i in range(1, 10)]
length = [i for i in range(10, 100)]


def sumOfFifth(num):
    num = str(num)
    ret = 0
    for n in num:
        n = int(n)
        ret += n ** 5
    return ret


upperBound = sumOfFifth(99999)
result = 0
for i in range(10, upperBound):
    print()
    if sumOfFifth(i) == i:
        result += i

print(result)
