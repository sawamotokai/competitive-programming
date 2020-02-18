import math


def primeFactorization(primeFactors, num):

    for i in range(2, math.ceil(num / 2) + 1):
        if num % i == 0:
            # print(num)
            primeFactors.append(int(i))
            return primeFactorization(primeFactors, num / i)
    primeFactors.insert(0, int(num))


# primeFactors = []

# primeFactorization(primeFactors, 28)

# print(primeFactors)


def numOfFactor(num):
    primeFactors = []
    primeFactorization(primeFactors, num)
    dic = {}
    ans = 1

    for n in primeFactors:
        if n in dic:
            dic[n] += 1
        else:
            dic[n] = 1

    for key in dic:
        ans *= dic[key] + 1

    print(dic)
    print(primeFactors)
    return ans


# def isDicOkay(dic):
#     if len(dic.keys()) >= 5:


# print(numOfFactor(62370000))

print(2 ** 4 * 3 ** 4 * 5 ** 4 * 7 * 11)


i = 1
acc = 0

while True:
    acc += i
    if acc > 62370000:
        target = numOfFactor(acc)
        print(target)
        print(acc)
        if target >= 500:
            break

    i += 1

