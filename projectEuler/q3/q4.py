import math

target = 600851475143


def isPrime(num):

    if num == 3:
        return True
    if num == 2:
        return True
    if num == 1:
        return False

    for i in range(2, math.ceil(num / 2) + 1):
        if num % i == 0:
            return False
    return True


def findSmallestPrimeFactor(num):
    # if isPrime(num):
    #     return num
    for i in range(1, int(num) + 1):
        if num % i == 0:
            if isPrime(i):
                print(i)
                return findSmallestPrimeFactor(int(num / i))


# print(findSmallestPrimeFactor(target))

print(isPrime(104723))
