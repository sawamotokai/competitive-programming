import math


def sum(num):
    return (1 + num) * num / 2


def sumOfSquare(num):
    ret = 0
    for i in range(1, num + 1):
        ret += i ** 2
    return ret


print(sum(100) ** 2 - sumOfSquare(100))

