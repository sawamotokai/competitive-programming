import math


def isPrime(num):
    for i in range(2, math.ceil(num / 2) + 1):
        if num % i == 0:
            return False
    return True


sum = 0

for j in range(2, 2000000):
    print(j)
    if isPrime(j):
        sum += j

print(sum)

